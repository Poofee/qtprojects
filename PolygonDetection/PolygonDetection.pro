TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    GraphicalPrimitives2D/Box2D.cpp \
    GraphicalPrimitives2D/Color.cpp \
    GraphicalPrimitives2D/Entity2D.cpp \
    GraphicalPrimitives2D/Line2D.cpp \
    GraphicalPrimitives2D/Point2D.cpp \
    GraphicalPrimitives2D/Polygon2D.cpp \
    GraphicalPrimitives2D/Polyline2D.cpp \
    GraphicalPrimitives2D/Vector2D.cpp \
    PolygonDetection/Line.cpp \
    PolygonDetection/line2d.cpp \
    PolygonDetection/LineSet.cpp \
    PolygonDetection/Polygon.cpp \
    PolygonDetection/PolygonDetector.cpp \
    PolygonDetection/PolygonSet.cpp \
    PolygonDetection/tinyxml/tinystr.cpp \
    PolygonDetection/tinyxml/tinyxml.cpp \
    PolygonDetection/tinyxml/tinyxmlerror.cpp \
    PolygonDetection/tinyxml/tinyxmlparser.cpp \
    PolygonDetection/graph_entities/Cycle.cpp \
    PolygonDetection/graph_entities/CycleSet.cpp \
    PolygonDetection/graph_entities/Edge.cpp \
    PolygonDetection/graph_entities/Graph.cpp \
    PolygonDetection/graph_entities/IncidenceMatrix.cpp \
    PolygonDetection/graph_entities/MatrixModuloTwo.cpp \
    PolygonDetection/graph_entities/Vertex.cpp

HEADERS += \
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
    PolygonDetection/Line.h \
    PolygonDetection/LineSet.h \
    PolygonDetection/PDConsts.h \
    PolygonDetection/PDMacros.h \
    PolygonDetection/Polygon.h \
    PolygonDetection/PolygonDetector.h \
    PolygonDetection/PolygonSet.h \
    PolygonDetection/tinyxml/tinystr.h \
    PolygonDetection/tinyxml/tinyxml.h \
    PolygonDetection/graph_entities/Cycle.h \
    PolygonDetection/graph_entities/CycleSet.h \
    PolygonDetection/graph_entities/Edge.h \
    PolygonDetection/graph_entities/Graph.h \
    PolygonDetection/graph_entities/IncidenceMatrix.h \
    PolygonDetection/graph_entities/MatrixModuloTwo.h \
    PolygonDetection/graph_entities/Vertex.h
