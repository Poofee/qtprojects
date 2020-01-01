QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DESTDIR = $$PWD/../bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    PolygonDetection/PolygonDetector.cpp \
    PolygonDetection/LineSet.cpp \
    PolygonDetection/PolygonSet.cpp \
    PolygonDetection/Polygon.cpp \
    PolygonDetection/Line.cpp \
    PolygonDetection/graph_entities/Cycle.cpp \
    PolygonDetection/graph_entities/CycleSet.cpp \
    PolygonDetection/graph_entities/Edge.cpp \
    PolygonDetection/graph_entities/Graph.cpp \
    PolygonDetection/graph_entities/IncidenceMatrix.cpp \
    PolygonDetection/graph_entities/MatrixModuloTwo.cpp \
    PolygonDetection/graph_entities/Vertex.cpp \
    GraphicalPrimitives2D/Box2D.cpp \
    GraphicalPrimitives2D/Color.cpp \
    GraphicalPrimitives2D/Entity2D.cpp \
    GraphicalPrimitives2D/Line2D.cpp \
    GraphicalPrimitives2D/Point2D.cpp \
    GraphicalPrimitives2D/Polygon2D.cpp \
    GraphicalPrimitives2D/Polyline2D.cpp \
    GraphicalPrimitives2D/Vector2D.cpp \
    PolygonDetection/tinyxml/tinystr.cpp \
    PolygonDetection/tinyxml/tinyxml.cpp \
    PolygonDetection/tinyxml/tinyxmlerror.cpp \
    PolygonDetection/tinyxml/tinyxmlparser.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    PolygonDetection/PolygonDetector.h \
    PolygonDetection/LineSet.h \
    PolygonDetection/PolygonSet.h \
    PolygonDetection/Polygon.h \
    PolygonDetection/Line.h \
    PolygonDetection/graph_entities/Cycle.h \
    PolygonDetection/graph_entities/CycleSet.h \
    PolygonDetection/graph_entities/Edge.h \
    PolygonDetection/graph_entities/Graph.h \
    PolygonDetection/graph_entities/IncidenceMatrix.h \
    PolygonDetection/graph_entities/MatrixModuloTwo.h \
    PolygonDetection/graph_entities/Vertex.h \
    GraphicalPrimitives2D/Box2D.h \
    GraphicalPrimitives2D/Color.h \
    GraphicalPrimitives2D/Entity2D.h \
    GraphicalPrimitives2D/GPConsts.h \
    GraphicalPrimitives2D/GPMacros.h \
    GraphicalPrimitives2D/Line2D.h \
    GraphicalPrimitives2D/Point2D.h \
    GraphicalPrimitives2D/Polygon2D.h \
    GraphicalPrimitives2D/Polyline2D.h \
    GraphicalPrimitives2D/Vector2D.h \
    macros.h \
    PolygonDetection/tinyxml/tinystr.h \
    PolygonDetection/tinyxml/tinyxml.h
