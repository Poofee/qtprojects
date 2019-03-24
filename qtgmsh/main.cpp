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
bool loadGmsh22(const char fn[]){
    char *ch = (char *)calloc(256,sizeof (char));
    //------------open file----------------------------------
    FILE * fp = NULL;
    fp = fopen(fn, "r");
    if (fp == NULL) {
        qDebug() << "Error: openning file!";
        return 1;
    }
    fgets(ch, 256, fp);
    double version;
    int file_type;
    int data_size;
    if(fscanf(fp,"%lf %d %d\n",&version,&file_type,&data_size) != 3){
        qDebug()<<"error reading format";
        return false;
    }else{
        qDebug()<<version<<file_type<<data_size;
        if(version > 2.2){
            qDebug()<<"Can only open gmsh version 2.2 format";
            return false;
        }
    }
    fgets(ch, 256, fp);
    fgets(ch, 256, fp);

    int number_nodes;
    if(fscanf(fp,"%d\n",&number_nodes) != 1)
    {
        return false;
    }else{
        /**读取节点坐标**/
        CNode *nodeList = (CNode *)malloc(number_nodes * sizeof (CNode));
        int index;
        for(int i = 0;i < number_nodes;++i){
            fscanf(fp,"%d %lf %lf %lf\n",&index,&nodeList[i].x,&nodeList[i].y,&nodeList[i].z);
            //qDebug()<<index<<nodeList[i].x<<nodeList[i].y<<nodeList[i].z;
        }
    }
    fgets(ch, 256, fp);
    fgets(ch, 256, fp);
    int number_ele;
    int ele_number;
    int elm_type;
    int number_of_tags;
    if(fscanf(fp,"%d\n",&number_ele) != 1){
        return false;
    }else{
        CElement *elementList = (CElement *)calloc(number_ele, sizeof (CElement));

        for(int i = 0;i < number_ele;++i){
            if(i == 2162){
                int a = 0;
            }
            fgets(ch, 256, fp);
            printf("%s",ch);
            ele_number = next_int(&ch);
            elm_type = next_int(&ch);
            number_of_tags = next_int(&ch);
            elementList[i].physic_tag = next_int(&ch);
            elementList[i].geometry_tag = next_int(&ch);

            int element_nodes = 0;
            switch (elm_type) {
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
                elementList[i].n[j] = next_int(&ch);
//            qDebug()<<elementList[i].geometry_tag;

        }
    }
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString gmsh_path = "D:\\fastFEM\\gmsh-4.2.2\\gmsh.exe";
    QStringList arguments;
    arguments<<"-setnumber"<<"disp"<<"0.0013"<<"-2"<<"-format"<<"msh2"<<"D:\\fastFEM\\model\\ddtlm\\modelpm.geo";

    QProcess *gmsh = new QProcess;
    /**阻塞式调用，只有程序执行结束后才会执行下面的语句**/
    gmsh->execute(gmsh_path,arguments);
    qDebug()<<"finish mesh";
    /**读入msh文件**/
    char mshFilename[] = "D:\\fastFEM\\model\\ddtlm\\modelpm.msh";
    loadGmsh22(mshFilename);
    qDebug()<<"Load mesh done!";
    return a.exec();
}
