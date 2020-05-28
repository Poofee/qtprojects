QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Geo
INCLUDEPATH += $$PWD/Common
INCLUDEPATH += $$PWD/Mesh
INCLUDEPATH += $$PWD/Numeric
INCLUDEPATH += $$PWD/Parser
INCLUDEPATH += $$PWD/Post


DESTDIR = $$PWD/../bin

DEFINES += _USE_MATH_DEFINES NOMINMAX WIN32

win32-msvc* {
    #ignore warning C4819
    QMAKE_CXXFLAGS += /wd"4819"
    QMAKE_CXXFLAGS *=  /wd"4100"
    contains (QMAKE_CXXFLAGS_WARN_ON, -w34100) : QMAKE_CXXFLAGS_WARN_ON -= -w34100
    DEFINES += _CRT_SECURE_NO_WARNINGS
}

HEADERS += \
    Common/avl.h \
    Common/Colors.h \
    Common/CommandLine.h \
    Common/Context.h \
    Common/CreateFile.h \
    Common/DefaultOptions.h \
    Common/GmshConfig.h \
    Common/GmshDefines.h \
    Common/GmshGlobal.h \
    Common/GmshMessage.h \
    Common/gmshPopplerWrapper.h \
    Common/GmshVersion.h \
    Common/Hash.h \
    Common/ListUtils.h \
    Common/MallocUtils.h \
    Common/Octree.h \
    Common/OctreeInternals.h \
    Common/OpenFile.h \
    Common/Options.h \
    Common/OS.h \
    Common/picojson.h \
    Common/rtree.h \
    Common/SmoothData.h \
    Common/StringUtils.h \
    Common/TreeUtils.h \
    Common/VertexArray.h \
    Geo/ACISEdge.h \
    Geo/ACISFace.h \
    Geo/ACISVertex.h \
    Geo/affineTransformation.h \
    Geo/boundaryLayersData.h \
    Geo/Cell.h \
    Geo/CellComplex.h \
    Geo/CGNSOptions.h \
    Geo/CGNSUtils.h \
    Geo/Chain.h \
    Geo/ChainComplex.h \
    Geo/closestPoint.h \
    Geo/closestVertex.h \
    Geo/discreteEdge.h \
    Geo/discreteFace.h \
    Geo/discreteRegion.h \
    Geo/discreteVertex.h \
    Geo/ExtrudeParams.h \
    Geo/findLinks.h \
    Geo/GEdge.h \
    Geo/GEdgeLoop.h \
    Geo/GEntity.h \
    Geo/Geo.h \
    Geo/GeoDefines.h \
    Geo/GeoInterpolation.h \
    Geo/GeomMeshMatcher.h \
    Geo/GeoStringInterface.h \
    Geo/GFace.h \
    Geo/ghostEdge.h \
    Geo/ghostFace.h \
    Geo/ghostRegion.h \
    Geo/GModel.h \
    Geo/GModelCreateTopologyFromMesh.h \
    Geo/GModelIO_ACIS.h \
    Geo/GModelIO_GEO.h \
    Geo/gmshEdge.h \
    Geo/gmshFace.h \
    Geo/gmshLevelset.h \
    Geo/gmshRegion.h \
    Geo/gmshSurface.h \
    Geo/gmshVertex.h \
    Geo/GPoint.h \
    Geo/GRegion.h \
    Geo/GVertex.h \
    Geo/Homology.h \
    Geo/intersectCurveSurface.h \
    Geo/MEdge.h \
    Geo/MEdgeHash.h \
    Geo/MElement.h \
    Geo/MElementCut.h \
    Geo/MElementOctree.h \
    Geo/MFace.h \
    Geo/MFaceHash.h \
    Geo/MHexahedron.h \
    Geo/MLine.h \
    Geo/MPoint.h \
    Geo/MPrism.h \
    Geo/MPyramid.h \
    Geo/MQuadrangle.h \
    Geo/MSubElement.h \
    Geo/MTetrahedron.h \
    Geo/MTriangle.h \
    Geo/MTrihedron.h \
    Geo/MVertex.h \
    Geo/MVertexBoundaryLayerData.h \
    Geo/MVertexRTree.h \
    Geo/OCCAttributes.h \
    Geo/OCCEdge.h \
    Geo/OCCFace.h \
    Geo/OCCRegion.h \
    Geo/OCCVertex.h \
    Geo/Pair.h \
    Geo/partitionEdge.h \
    Geo/partitionFace.h \
    Geo/partitionRegion.h \
    Geo/partitionVertex.h \
    Geo/Range.h \
    Geo/SBoundingBox3d.h \
    Geo/SOrientedBoundingBox.h \
    Geo/SPoint2.h \
    Geo/SPoint3.h \
    Geo/STensor3.h \
    Geo/SVector3.h \
    Geo/xyEdge.h \
    Geo/xyFace.h \
    Mesh/BackgroundMesh.h \
    Mesh/BackgroundMeshTools.h \
    Mesh/BDS.h \
    Mesh/BoundaryLayers.h \
    Mesh/delaunay3d.h \
    Mesh/DivideAndConquer.h \
    Mesh/Field.h \
    Mesh/FieldPython.h \
    Mesh/filterElements.h \
    Mesh/Generator.h \
    Mesh/HighOrder.h \
    Mesh/meshGEdge.h \
    Mesh/meshGFace.h \
    Mesh/meshGFaceBamg.h \
    Mesh/meshGFaceBDS.h \
    Mesh/meshGFaceDelaunayInsertion.h \
    Mesh/meshGFaceOptimize.h \
    Mesh/meshGRegion.h \
    Mesh/meshGRegionBoundaryRecovery.h \
    Mesh/meshGRegionDelaunayInsertion.h \
    Mesh/meshGRegionHxt.h \
    Mesh/meshGRegionLocalMeshMod.h \
    Mesh/meshGRegionMMG3D.h \
    Mesh/meshGRegionNetgen.h \
    Mesh/meshMetric.h \
    Mesh/meshPartition.h \
    Mesh/meshRelocateVertex.h \
    Mesh/qualityMeasures.h \
    Mesh/qualityMeasuresJacobian.h \
    Mesh/tetgenBR.h \
    Numeric/approximationError.h \
    Numeric/BasisFactory.h \
    Numeric/BergotBasis.h \
    Numeric/bezierBasis.h \
    Numeric/cartesian.h \
    Numeric/CondNumBasis.h \
    Numeric/ConjugateGradients.h \
    Numeric/decasteljau.h \
    Numeric/discreteFrechetDistance.h \
    Numeric/ElementType.h \
    Numeric/fullMatrix.h \
    Numeric/FuncSpaceData.h \
    Numeric/GaussIntegration.h \
    Numeric/GaussJacobi1D.h \
    Numeric/GaussLegendre1D.h \
    Numeric/hausdorffDistance.h \
    Numeric/HilbertCurve.h \
    Numeric/incompleteBasis.h \
    Numeric/InnerVertexPlacement.h \
    Numeric/Iso.h \
    Numeric/JacobianBasis.h \
    Numeric/mathEvaluator.h \
    Numeric/miniBasis.h \
    Numeric/nanoflann.hpp \
    Numeric/nodalBasis.h \
    Numeric/Numeric.h \
    Numeric/orthogonalBasis.h \
    Numeric/pointsGenerators.h \
    Numeric/polynomialBasis.h \
    Numeric/pyramidalBasis.h \
    Numeric/robustPredicates.h \
    Numeric/simpleFunction.h \
    Numeric/simpleFunctionPython.h \
    Common/gmsh.h \
    Common/gmshc.h \
    Geo/GModelIO_OCC.h \
    Parser/FunctionManager.h \
    Parser/Gmsh.tab.hpp \
    Parser/Parser.h \
    Post/ColorTable.h

SOURCES += \
    Common/avl.cpp \
    Common/CommandLine.cpp \
    Common/Context.cpp \
    Common/CreateFile.cpp \
    Common/gmsh.cpp \
    Common/GmshGlobal.cpp \
    Common/GmshMessage.cpp \
    Common/gmshPopplerWrapper.cpp \
    Common/ListUtils.cpp \
    Common/MallocUtils.cpp \
    Common/Octree.cpp \
    Common/OctreeInternals.cpp \
    Common/onelabUtils.cpp \
    Common/OpenFile.cpp \
    Common/Options.cpp \
    Common/OS.cpp \
    Common/SmoothData.cpp \
    Common/StringUtils.cpp \
    Common/TreeUtils.cpp \
    Common/VertexArray.cpp \
    Geo/ACISEdge.cpp \
    Geo/ACISFace.cpp \
    Geo/ACISVertex.cpp \
    Geo/affineTransformation.cpp \
    Geo/boundaryLayersData.cpp \
    Geo/Cell.cpp \
    Geo/CellComplex.cpp \
    Geo/CGNSUtils.cpp \
    Geo/Chain.cpp \
    Geo/ChainComplex.cpp \
    Geo/closestPoint.cpp \
    Geo/closestVertex.cpp \
    Geo/discreteEdge.cpp \
    Geo/discreteFace.cpp \
    Geo/discreteRegion.cpp \
    Geo/discreteVertex.cpp \
    Geo/ExtrudeParams.cpp \
    Geo/findLinks.cpp \
    Geo/GEdge.cpp \
    Geo/GEdgeLoop.cpp \
    Geo/GEntity.cpp \
    Geo/Geo.cpp \
    Geo/GeoInterpolation.cpp \
    Geo/GeomMeshMatcher.cpp \
    Geo/GeoStringInterface.cpp \
    Geo/GFace.cpp \
    Geo/GModel.cpp \
    Geo/GModelCreateTopologyFromMesh.cpp \
    Geo/GModelIO_ACIS.cpp \
    Geo/GModelIO_ACTRAN.cpp \
    Geo/GModelIO_BDF.cpp \
    Geo/GModelIO_CELUM.cpp \
    Geo/GModelIO_CGNS.cpp \
    Geo/GModelIO_DIFF.cpp \
    Geo/GModelIO_GEO.cpp \
    Geo/GModelIO_GEOM.cpp \
    Geo/GModelIO_INP.cpp \
    Geo/GModelIO_IR3.cpp \
    Geo/GModelIO_KEY.cpp \
    Geo/GModelIO_MAIL.cpp \
    Geo/GModelIO_MATLAB.cpp \
    Geo/GModelIO_MED.cpp \
    Geo/GModelIO_MESH.cpp \
    Geo/GModelIO_MSH.cpp \
    Geo/GModelIO_MSH2.cpp \
    Geo/GModelIO_MSH3.cpp \
    Geo/GModelIO_MSH4.cpp \
    Geo/GModelIO_NEU.cpp \
    Geo/GModelIO_P3D.cpp \
    Geo/GModelIO_PLY.cpp \
    Geo/GModelIO_POS.cpp \
    Geo/GModelIO_SAMCEF.cpp \
    Geo/GModelIO_STL.cpp \
    Geo/GModelIO_SU2.cpp \
    Geo/GModelIO_TOCHNOG.cpp \
    Geo/GModelIO_UNV.cpp \
    Geo/GModelIO_VRML.cpp \
    Geo/GModelIO_VTK.cpp \
    Geo/GModelVertexArrays.cpp \
    Geo/gmshEdge.cpp \
    Geo/gmshFace.cpp \
    Geo/gmshLevelset.cpp \
    Geo/gmshRegion.cpp \
    Geo/gmshSurface.cpp \
    Geo/gmshVertex.cpp \
    Geo/GRegion.cpp \
    Geo/GVertex.cpp \
    Geo/Homology.cpp \
    Geo/intersectCurveSurface.cpp \
    Geo/MEdge.cpp \
    Geo/MElement.cpp \
    Geo/MElementCut.cpp \
    Geo/MElementOctree.cpp \
    Geo/MFace.cpp \
    Geo/MHexahedron.cpp \
    Geo/MLine.cpp \
    Geo/MPrism.cpp \
    Geo/MPyramid.cpp \
    Geo/MQuadrangle.cpp \
    Geo/MSubElement.cpp \
    Geo/MTetrahedron.cpp \
    Geo/MTriangle.cpp \
    Geo/MTrihedron.cpp \
    Geo/MVertex.cpp \
    Geo/MVertexBoundaryLayerData.cpp \
    Geo/OCCEdge.cpp \
    Geo/OCCFace.cpp \
    Geo/OCCRegion.cpp \
    Geo/OCCVertex.cpp \
    Geo/SOrientedBoundingBox.cpp \
    Geo/STensor3.cpp \
    Mesh/BackgroundMesh.cpp \
    Mesh/BackgroundMeshTools.cpp \
    Mesh/BDS.cpp \
    Mesh/BoundaryLayers.cpp \
    Mesh/delaunay3d.cpp \
    Mesh/DivideAndConquer.cpp \
    Mesh/Field.cpp \
    Mesh/filterElements.cpp \
    Mesh/Generator.cpp \
    Mesh/HighOrder.cpp \
    Mesh/meshGEdge.cpp \
    Mesh/meshGEdgeExtruded.cpp \
    Mesh/meshGFace.cpp \
    Mesh/meshGFaceBamg.cpp \
    Mesh/meshGFaceBDS.cpp \
    Mesh/meshGFaceDelaunayInsertion.cpp \
    Mesh/meshGFaceExtruded.cpp \
    Mesh/meshGFaceOptimize.cpp \
    Mesh/meshGFaceTransfinite.cpp \
    Mesh/meshGRegion.cpp \
    Mesh/meshGRegionBoundaryLayer.cpp \
    Mesh/meshGRegionBoundaryRecovery.cpp \
    Mesh/meshGRegionCarveHole.cpp \
    Mesh/meshGRegionDelaunayInsertion.cpp \
    Mesh/meshGRegionExtruded.cpp \
    Mesh/meshGRegionHxt.cpp \
    Mesh/meshGRegionLocalMeshMod.cpp \
    Mesh/meshGRegionMMG3D.cpp \
    Mesh/meshGRegionNetgen.cpp \
    Mesh/meshGRegionTransfinite.cpp \
    Mesh/meshMetric.cpp \
    Mesh/meshPartition.cpp \
    Mesh/meshRefine.cpp \
    Mesh/meshRelocateVertex.cpp \
    Mesh/qualityMeasures.cpp \
    Mesh/qualityMeasuresJacobian.cpp \
    Mesh/tetgenBR.cxx \
    Numeric/approximationError.cpp \
    Numeric/BasisFactory.cpp \
    Numeric/BergotBasis.cpp \
    Numeric/bezierBasis.cpp \
    Numeric/CondNumBasis.cpp \
    Numeric/ConjugateGradients.cpp \
    Numeric/decasteljau.cpp \
    Numeric/discreteFrechetDistance.cpp \
    Numeric/ElementType.cpp \
    Numeric/fullMatrix.cpp \
    Numeric/FuncSpaceData.cpp \
    Numeric/GaussIntegration.cpp \
    Numeric/GaussJacobi1D.cpp \
    Numeric/GaussLegendreSimplex.cpp \
    Numeric/GaussQuadratureHex.cpp \
    Numeric/GaussQuadratureLin.cpp \
    Numeric/GaussQuadraturePri.cpp \
    Numeric/GaussQuadraturePyr.cpp \
    Numeric/GaussQuadratureQuad.cpp \
    Numeric/GaussQuadratureTet.cpp \
    Numeric/GaussQuadratureTri.cpp \
    Numeric/hausdorffDistance.cpp \
    Numeric/HilbertCurve.cpp \
    Numeric/incompleteBasis.cpp \
    Numeric/InnerVertexPlacement.cpp \
    Numeric/Iso.cpp \
    Numeric/JacobianBasis.cpp \
    Numeric/mathEvaluator.cpp \
    Numeric/miniBasis.cpp \
    Numeric/nodalBasis.cpp \
    Numeric/Numeric.cpp \
    Numeric/orthogonalBasis.cpp \
    Numeric/pointsGenerators.cpp \
    Numeric/polynomialBasis.cpp \
    Numeric/pyramidalBasis.cpp \
    Numeric/robustPredicates.cpp \
    main.cpp \
    Geo/GModelIO_OCC.cpp \
    Parser/FunctionManager.cpp \
    Parser/Gmsh.tab.cpp \
    Parser/Gmsh.yy.cpp \
    Post/ColorTable.cpp

