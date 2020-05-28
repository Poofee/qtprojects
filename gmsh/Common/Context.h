// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CONTEXT_H
#define CONTEXT_H

#include <vector>
#include <map>
#include <string>
#include "CGNSOptions.h"

#define NUM_SOLVERS 10

//class GamePad;

struct contextMeshOptions {
  // mesh algorithms
  int optimize, optimizeNetgen, refineSteps;
  int smoothCrossField, crossFieldClosestPoint;
  double lcFactor, randFactor, randFactor3d, lcIntegrationPrecision;
  double optimizeThreshold, normals, tangents, explode, angleSmoothNormals;
  double allowSwapEdgeAngle;
  double qualityInf, qualitySup, radiusInf, radiusSup;
  double lcMin, lcMax, toleranceEdgeLength, toleranceInitialDelaunay;
  double anisoMax, smoothRatio;
  int lcFromPoints, lcFromCurvature, lcExtendFromBoundary;
  int nbSmoothing, algo2d, algo3d, algoSubdivide;
  int algoRecombine, recombineAll, recombineOptimizeTopology;
  int recombine3DAll, recombine3DLevel;
  int recombine3DConformity, flexibleTransfinite;
  int order, secondOrderLinear, secondOrderIncomplete, secondOrderExperimental;
  int meshOnlyVisible, minCircPoints, minCurvPoints;
  int hoOptimize, hoPeriodic, hoNLayers, hoPrimSurfMesh, hoIterMax, hoPassMax;
  double hoThresholdMin, hoThresholdMax, hoPoissonRatio;
  std::map<int, int> algo2dPerFace;
  std::map<int, int> curvatureControlPerFace;
  int NewtonConvergenceTestXYZ;
  int ignorePeriodicity, boundaryLayerFanPoints;
  int maxNumThreads1D, maxNumThreads2D, maxNumThreads3D;
  double angleToleranceFacetOverlap;
  int renumber;
  // mesh IO
  int fileFormat;
  double mshFileVersion, medFileMinorVersion, scalingFactor;
  int medImportGroupsOfNodes;
  int saveAll, saveTri, saveGroupsOfNodes, binary, bdfFieldFormat;
  int unvStrictFormat, stlRemoveDuplicateTriangles, stlOneSolidPerSurface;
  int saveParametric, saveTopology, zoneDefinition;
  int saveElementTagType, switchElementTags;
  int cgnsImportOrder, cgnsConstructTopology;
  int preserveNumberingMsh2;
  // partitioning
  int numPartitions, partitionCreateTopology, partitionCreateGhostCells;
  int partitionCreatePhysicals, partitionSplitMeshFiles,
    partitionSaveTopologyFile;
  int partitionTriWeight, partitionQuaWeight, partitionTetWeight,
    partitionHexWeight, partitionLinWeight;
  int partitionPriWeight, partitionPyrWeight, partitionTrihWeight;
  int partitionOldStyleMsh2;
  int metisAlgorithm, metisEdgeMatching, metisRefinementAlgorithm;
  // mesh display
  int draw, changed, light, lightTwoSide, lightLines, pointType;
  int points, lines, triangles, quadrangles, tetrahedra, hexahedra, prisms;
  int pyramids, trihedra;
  int surfacesEdges, surfacesFaces, volumesEdges, volumesFaces, numSubEdges;
  int pointsNum, linesNum, surfacesNum, volumesNum, qualityType, labelType;
  double pointSize, lineWidth;
  int dual, voronoi, drawSkinOnly, colorCarousel, labelSampling;
  int smoothNormals, clip;
};

struct contextGeometryOptions {
  // geometry algorithms
  int oldCircle, oldNewreg, oldRuledSurface;
  int extrudeSplinePoints, extrudeReturnLateral;
  int autoCoherence;
  double tolerance, toleranceBoolean, snap[3], transform[3][3], offset[3];
  int occAutoFix, occFixDegenerated, occFixSmallEdges, occFixSmallFaces;
  int occSewFaces, occParallel, occBooleanPreserveNumbering;
  int occDisableSTL, occImportLabels;
  double occScaling;
  std::string occTargetUnit;
  int copyMeshingMethod, exactExtrusion;
  int matchGeomAndMesh;
  double matchMeshScaleFactor;
  double matchMeshTolerance;
  int hideCompounds, orientedPhysicals;
  int reparamOnFaceRobust;
  // geometry display
  int draw, light, lightTwoSide, points, curves, surfaces, volumes;
  int pointsNum, curvesNum, surfacesNum, volumesNum, labelType;
  double pointSize, curveWidth, selectedPointSize, selectedCurveWidth;
  int pointType, curveType, surfaceType, numSubEdges;
  double normals, tangents, scalingFactor;
  int highlightOrphans, clip, useTransform;
  int doubleClickedEntityTag;
  std::string doubleClickedPointCommand, doubleClickedCurveCommand;
  std::string doubleClickedSurfaceCommand, doubleClickedVolumeCommand;
};

// The interface-independent context.
class CTX {
private:
  static CTX *_instance;

public:
  CTX();
  ~CTX();
  static CTX *instance();
 public:
  // for debug purposes only, i.e. JF and CG personal use
  int debugSurface;
  // files on the command line and various file names
  std::vector<std::string> files;
  std::string bgmFileName, outputFileName, defaultFileName, tmpFileName;
  std::string sessionFileName, optionsFileName, errorFileName;
  std::string meshStatReportFileName;
  // filename of the executable, with full path
  std::string exeFileName;
  // the home directory
  std::string homeDir;
  // file history
  std::vector<std::string> recentFiles;
  // create mesh statistics report (0: do nothing, 1: create, 2: append)
  int createAppendMeshStatReport;
  // should we launch a solver at startup?
  int launchSolverAtStartup;
  // save session/option file on exit?
  int sessionSave, optionsSave;
  // ask confirmation when overwriting files?
  int confirmOverwrite;
  // forced display host:0.0 under X11
  std::string display;
  // FLTK theme
  std::string guiTheme;
  // FLTK color scheme
  int guiColorScheme;
  // print messages on to the terminal?
  int terminal;
  // number of graphical windows/tiles
  int numWindows, numTiles;
  // text editor command (with included '%s')
  std::string editor;
  // pattern of files to watch out for
  std::string watchFilePattern;
  // show tootips in the GUI?
  int tooltips;
  // position and size of various windows in the GUI
  int glPosition[2], glSize[2], msgSize, menuPosition[2], menuSize[2],
    detachedMenu;
  int optPosition[2], visPosition[2], hotPosition[2], clipPosition[2],
    manipPosition[2];
  int statPosition[2], ctxPosition[2];
  int pluginPosition[2], pluginSize[2], fieldPosition[2], fieldSize[2];
  int fileChooserPosition[2], extraPosition[2], extraSize[2];
  // use the system menu bar on Mac OS X?
  int systemMenuBar;
  // show standard Gmsh menu in onelab window
  int showModuleMenu;
  // use high-resolution opengl graphics (retina Macs)
  int highResolutionGraphics;
  // batch mode (-4: lua session, -3: server daemon, -2: check coherence, -1:
  // write geo, 0: full gfx, 1: 1D mesh, 2: 2D mesh, 3: 3D mesh, 4: adapt mesh,
  // 5: refine mesh, 6: reclassify mesh)
  int batch;
  // batch operations to apply after meshing (1: partition mesh)
  int batchAfterMesh;
  // mesh discrete faces / edges
  int meshDiscrete;
  // initial menu (0: automatic, 1: geom, 2: mesh, 3: solver, 4: post)
  int initialContext;
  // show some windows on startup?
  int showOptionsOnStartup, showMessagesOnStartup;
  // never popup dialogs in scripts (use default values instead)?
  int noPopup;
  // make all windows "non modal"?
  int nonModalWindows;
  // clipping plane distance factor
  double clipFactor;
  // display border factor (0 = model fits window size exactly)
  double displayBorderFactor;
  // do or do not use the trackball for rotations
  int useTrackball, trackballHyperbolicSheet;
  // gamepad controller
//  GamePad *gamepad;
  // point around which to rotate the scene
  double rotationCenter[3];
  // rotate around the center of mass instead of rotationCenter[]
  int rotationCenterCg;
  // "overall" x, y and z min used for drawing and lc computation
  double min[3], max[3];
  // "center of mass" of the current geometry, used for graphics only
  double cg[3];
  // characteristic length for the whole problem (never used in mesh
  // generation ->only for geo/post)
  double lc;
  // double buffer/antialias/stereo graphics?
  int db, antialiasing, stereo, camera;
  bool fileread;
  double eye_sep_ratio, focallength_ratio, camera_aperture;
  // orthogonal projection?
  int ortho;
  // draw the bounding boxes and the rot center?
  int drawBBox, drawRotationCenter;
  // draw simplified model during user interaction?
  int fastRedraw;
  // small axes options
  int smallAxes, smallAxesSize, smallAxesPos[2];
  // large axes options
  int axes, axesAutoPosition, axesMikado, axesForceValue;
  double axesPosition[6], axesValue[6], axesTics[3];
  std::string axesLabel[3], axesFormat[3];
  // simple dynamic lock (should be a mutex)
  int lock;
  // enable alpha blending?
  int alpha;
  // mouse2 zoom coefficient
  double zoomFactor;
  // draw background gradient?
  int bgGradient;
  // draw background image?
  std::string bgImageFileName;
  double bgImagePosition[2], bgImageSize[2];
  int bgImage3d, bgImagePage;
  // fltk font size (and delta for palette windows)
  int fontSize, deltaFontSize;
  // font name, FLTK enum and size for opengl graphics
  std::string glFont, glFontTitle, glFontEngine;
  int glFontEnum, glFontEnumTitle, glFontSize, glFontSizeTitle;
  // font size of messages
  int msgFontSize;
  // point/line widths
  double pointSize, lineWidth;
  double highResolutionPointSizeFactor;
  // light options
  int light[6];
  double lightPosition[6][4], shine, shineExponent;
  // clipping plane options
  double clipPlane[6][4];
  int clipWholeElements, clipOnlyDrawIntersectingVolume, clipOnlyVolume;
  // polygon offset options
  int polygonOffset, polygonOffsetAlways;
  double polygonOffsetFactor, polygonOffsetUnits;
  // color scheme
  int colorScheme;
  // number of subdivisions for gluQuadrics
  int quadricSubdivisions;
  // vector display type and options (for normals, etc.)
  int vectorType;
  double arrowRelHeadRadius, arrowRelStemRadius, arrowRelStemLength;
  // records cpu times for 1-D, 2-D and 3-D mesh generation
  double meshTimer[3];
  // dynamic variable tracking if the bbox is currently imposed
  int forcedBBox;
  // enable selection/hover/picking using the mouse
  int mouseSelection, mouseHoverMeshes, pickElements;
  // invert sense of mouse wheel zoom
  int mouseInvertZoom;
  // disable some warnings for expert users?
  int expertMode;
#if defined(HAVE_VISUDEV)
  // Enable heavy visualization capabilities (for development purpose)
  int heavyVisu;
#endif
  // dynamic: equal to 1 while gmsh is printing
  int printing;
  // hide all unselected entities?
  int hideUnselected;
  // temporary storage of rotation, translation, scale (until the GUI
  // is ready)
  double tmpRotation[3], tmpTranslation[3], tmpScale[3], tmpQuaternion[4];
  // geometry options
  contextGeometryOptions geom;
  // mesh options
  contextMeshOptions mesh;
  CGNSOptions cgnsOptions;
  // post processing options
  struct {
    int draw, link, horizontalScales;
    int smooth, animCycle, animStep, combineTime, combineRemoveOrig;
    int fileFormat, plugins, forceNodeData, forceElementData;
    int saveMesh, saveInterpolationMatrices;
    double animDelay;
    std::string doubleClickedGraphPointCommand;
    double doubleClickedGraphPointX, doubleClickedGraphPointY;
    int doubleClickedView;
  } post;
  // solver options
  struct {
    int plugins, listen;
    double timeout;
    std::string socketName, pythonInterpreter, octaveInterpreter;
    std::string name[NUM_SOLVERS], extension[NUM_SOLVERS];
    std::string executable[NUM_SOLVERS], remoteLogin[NUM_SOLVERS];
    int autoSaveDatabase, autoLoadDatabase;
    int autoArchiveOutputFiles, autoMesh, autoMergeFile;
    int autoShowViews, autoShowLastStep, autoCheck, showInvisibleParameters;
  } solver;
  // print options
  struct {
    int fileFormat, epsQuality, epsCompress, epsPS3Shading;
    int epsOcclusionCulling, epsBestRoot;
    double epsLineWidthFactor, epsPointSizeFactor;
    int jpegQuality, jpegSmoothing, geoLabels, geoOnlyPhysicals;
    int text, texAsEquation;
    int gifDither, gifSort, gifInterlace, gifTransparent;
    int posElementary, posElement, posGamma, posEta, posSICN, posSIGE, posDisto;
    int compositeWindows, deleteTmpFiles, background;
    int width, height;
    double parameter, parameterFirst, parameterLast, parameterSteps;
    int pgfTwoDim, pgfExportAxis, pgfHorizBar;
    std::string parameterCommand;
    int x3dCompatibility, x3dRemoveInnerBorders;
    double x3dPrecision, x3dTransparency;
  } print;
  // color options
  struct {
    unsigned int bg, bgGrad, fg, text, axes, smallAxes;
    unsigned int ambientLight[6], diffuseLight[6], specularLight[6];
    struct {
      unsigned int point, curve, surface, volume;
      unsigned int selection, highlight[3], projection;
      unsigned int tangents, normals;
    } geom;
    struct {
      unsigned int node, nodeSup, line, triangle, quadrangle;
      unsigned int tetrahedron, hexahedron, prism, pyramid, trihedron;
      unsigned int carousel[20];
      unsigned int tangents, normals;
    } mesh;
  } color;
  // is the machine big-endian?
  int bigEndian;
  // how RGBA values are packed and unpacked into/from an unsigned integer to be
  // fed to glColor4ubv (depends on machine byte ordering!):
  unsigned int packColor(int R, int G, int B, int A);
  int unpackRed(unsigned int X);
  int unpackGreen(unsigned int X);
  int unpackBlue(unsigned int X);
  int unpackAlpha(unsigned int X);
};

#endif
