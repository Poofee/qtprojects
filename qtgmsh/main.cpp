#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString gmsh_path = "D:\\fastFEM\\gmsh-4.2.2\\gmsh.exe";
    QStringList arguments;
    arguments<<"-setnumber"<<"disp"<<"0.001"<<"-2"<<"D:\\fastFEM\\model\\ddtlm\\modelpm.msh";

    QProcess *gmsh = new QProcess;
    /**阻塞式调用，只有程序执行结束后才会执行下面的语句**/
    gmsh->execute(gmsh_path,arguments);

    qDebug()<<"finish mesh";
    return a.exec();
}
