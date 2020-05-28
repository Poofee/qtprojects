#include "gmsh.h"

#include <QCoreApplication>

void test1();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test1();

    return a.exec();
}

void test1(){
    int myargn = 6;
    char *myargv[] = {(char*)"gmsh",(char*)"-setnumber",(char*)"disp",(char*)"0.001",(char*)"-format",(char*)"msh2"};
    gmsh::initialize(myargn,myargv);
    gmsh::option::setNumber("General.Terminal", 1);
    gmsh::open("../bin/modelpm.geo");
    gmsh::model::mesh::generate(2);
    gmsh::write("modelpm.msh");
    gmsh::finalize();
}
