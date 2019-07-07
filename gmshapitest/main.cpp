#include "widget.h"
#include <QApplication>
#include "include/gmsh.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    gmsh::initialize(argc, argv);
//    gmsh::model::add("square");
//    gmsh::model::geo::addPoint(0, 0, 0, 0.1, 1);
//    gmsh::model::geo::addPoint(1, 0, 0, 0.1, 2);
//    gmsh::model::geo::addPoint(1, 1, 0, 0.1, 3);
//    gmsh::model::geo::addPoint(0, 1, 0, 0.1, 4);
//    gmsh::model::geo::addLine(1, 2, 1);
//    gmsh::model::geo::addLine(2, 3, 2);
//    gmsh::model::geo::addLine(3, 4, 3);
//    // try automatic assignement of tag
//    int line4 = gmsh::model::geo::addLine(4, 1);
//    gmsh::model::geo::addCurveLoop({1, 2, 3, line4}, 1);
//    gmsh::model::geo::addPlaneSurface({1}, 6);
//    gmsh::model::geo::synchronize();
//    gmsh::model::mesh::generate(2);
//    gmsh::write("square.msh");

    int myargn = 6;
    char *myargv[] = {"gmsh","-setnumber","disp","0.001","-format","msh2"};
    gmsh::initialize(myargn,myargv);
    gmsh::option::setNumber("General.Terminal", 1);
    gmsh::open("../bin/modelpm.geo");
    gmsh::model::mesh::generate(2);
    gmsh::write("modelpm.msh");
    gmsh::finalize();
    return a.exec();
}
