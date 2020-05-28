#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <stdio.h>

enum GmshElementType{
    LINE_NODE2=1,
    TRIANGLE_NODE3,
    QUAD_NODE4
};
typedef struct _CNode
{
    double x, y, z;
}CNode;

typedef struct _CElement
{
    int n[3];// ni, nj, nk;//
    int ele_type;
    int physic_tag;
    int geometry_tag;
}CElement;
int next_int(char **start)
{
    int i;
    char *end;

    i = strtol(*start,&end,10);
    *start = end;
    return(i);
}
/*!
 \brief 读入msh2.2版本的分网文件，这个版本的格式比较容易读取。
 格式简要如下：
$MeshFormat
版本号（2.2） 文件类型（0代表ASCII文件） 数据大小
$EndMeshFormat
$Nodes
节点数目
节点编号 x y z
...
$EndNodes
$Elements
单元数目
单元编号 单元类型 标签数 标签1（物理实体编号） 标签2（几何实体编号） ... 节点1 节点2 节点3 ...
...
$EndElements
 \param mshFilename
 \return bool
*/
bool loadGmsh22(const char fn[],FILE* fp1,double dis){
    char *ch = (char *)calloc(256,sizeof (char));
    //------------open file----------------------------------
    FILE * fp = nullptr;
    fp = fopen(fn, "r");
    if (fp == nullptr) {
        qDebug() << "Error: openning file!";
        return 1;
    }
    while(!feof(fp)){
        fgets(ch, 256, fp);

        if(strstr(ch,"$MeshFormat")){
            fprintf(fp1,"$MeshFormat\n");
            double version;
            int file_type;
            int data_size;
            if(fscanf(fp,"%lf %d %d\n",&version,&file_type,&data_size) != 3){
                qDebug()<<"error reading format";
                return false;
            }else{
                qDebug()<<version<<file_type<<data_size;
                fprintf(fp1,"%lf %d %d\n",version,file_type,data_size);
                if(version > 2.2){
                    qDebug()<<"Can only open gmsh version 2.2 format";
                    return false;
                }
            }
            fgets(ch, 256, fp);
            if(!strstr(ch,"$EndMeshFormat")) {
                printf("$MeshFormat section should end to string $EndMeshFormat:\n%s\n",ch);
            }
            fprintf(fp1,"$EndMeshFormat\n");
        }else if(strstr(ch,"$Nodes")){
            int number_nodes;
            fprintf(fp1,"$Nodes\n");
            if(fscanf(fp,"%d\n",&number_nodes) != 1)
            {
                return false;
            }else{
                fprintf(fp1,"%d\n",number_nodes);
                /**读取节点坐标**/
                CNode *nodeList = (CNode *)malloc(number_nodes * sizeof (CNode));
                int index;
                for(int i = 0;i < number_nodes;++i){
                    fscanf(fp,"%d %lf %lf %lf\n",&index,&nodeList[i].x,&nodeList[i].y,&nodeList[i].z);
                    fprintf(fp1,"%d %lf %lf %lf\n",index,nodeList[i].x,nodeList[i].y+dis,nodeList[i].z);
                    //qDebug()<<index<<nodeList[i].x<<nodeList[i].y<<nodeList[i].z;
                }
            }
            fgets(ch, 256, fp);
            if(!strstr(ch,"$EndNodes")) {
                printf("$Node section should end to string $EndNodes:\n%s\n",ch);
            }
            fprintf(fp1,"$EndNodes\n");
        }else if(strstr(ch,"$Elements")){
            fprintf(fp1,"$Elements\n");
            int number_ele;
            int ele_number;
            //    int elm_type;
            int number_of_tags;
            char * chtmp;
            if(fscanf(fp,"%d\n",&number_ele) != 1){
                return false;
            }else{
                fprintf(fp1,"%d\n",number_ele);
                CElement *elementList = (CElement *)calloc(number_ele, sizeof (CElement));

                for(int i = 0;i < number_ele;++i){
                    chtmp = fgets(ch, 256, fp);
                    ele_number = next_int(&chtmp);
                    elementList[i].ele_type = next_int(&chtmp);
                    number_of_tags = next_int(&chtmp);
                    elementList[i].physic_tag = next_int(&chtmp);
                    elementList[i].geometry_tag = next_int(&chtmp);

                    fprintf(fp1,"%d %d %d %d %d",ele_number,elementList[i].ele_type,number_of_tags,elementList[i].physic_tag,elementList[i].geometry_tag);
                    int element_nodes = 0;
                    switch (elementList[i].ele_type) {
                    case 15:
                        element_nodes = 1;
                        break;
                    case 1:
                        element_nodes = 2;
                        break;
                    case 2:
                        element_nodes = 3;
                        break;
                    default:
                        element_nodes = 0;
                        break;
                    }

                    for(int j = 0; j < element_nodes;++j)
                        elementList[i].n[j] = next_int(&chtmp)-1;
                    for(int j = 0; j < element_nodes;++j)
                        fprintf(fp1," %d",elementList[i].n[j]+1);
                    //qDebug()<<elementList[i].geometry_tag<<elementList[i].physic_tag
                     //      <<elementList[i].n[0]<<elementList[i].n[1]<<elementList[i].n[2];

                    fprintf(fp1,"\n");
                }
            }
            fgets(ch, 256, fp);
            if(!strstr(ch,"$EndElements")) {
                printf("$Element section should end to string $EndElements:\n%s\n",ch);
            }
            fprintf(fp1,"$EndElements\n");
        }
    }

    fclose(fp);
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QString gmsh_path = "D:\\fastFEM\\gmsh-4.2.2\\gmsh.exe";
    //QStringList arguments;
    //arguments<<"-setnumber"<<"disp"<<"0.0013"<<"-2"<<"-format"<<"msh2"<<"D:\\fastFEM\\model\\ddtlm\\modelpm.geo";

    //QProcess *gmsh = new QProcess;
    /**阻塞式调用，只有程序执行结束后才会执行下面的语句**/
    //gmsh->execute(gmsh_path,arguments);
    //qDebug()<<"finish mesh";
    /**读入msh文件**/
    char mshFilename[] = "D:\\winmac\\fastFEM\\matlab\\2.5jrs1250\\mesh18.msh";
    char backmshFilename[] = "D:\\winmac\\fastFEM\\matlab\\2.5jrs1250\\mesh18copy.msh";
    FILE* fp = fopen(backmshFilename,"w");
    loadGmsh22(mshFilename,fp,0.1*(18-1));
    qDebug()<<"Load mesh done!";
    fclose(fp);
    return a.exec();
}
