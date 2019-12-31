#include ".\polygondetector.h"
#include ".\PDConsts.h"
#include ".\PDMacros.h"

#include "tinyxml/tinyxml.h"

//#include <wx/log.h>

using namespace PolygonDetection;

bool PolygonDetector::_interrupted = false;
bool PolygonDetector::_time_exceeded = false;
unsigned long PolygonDetector::_max_processing_time = MAX_PROCESSING_TIME_DEFAULT;
bool PolygonDetector::_silent = SILENT_POLYGON_DETECTION_BY_DEFAULT;

PolygonDetector::PolygonDetector(void)
{
}

PolygonDetector::~PolygonDetector(void)
{
}

/**
* @descr Reads a set of lines to the current line set
*/
bool PolygonDetector::ReadSVGfile(const char * filename) {
	if (!filename) {
        printf("Invalid filename.");
		return false;
	}

	if (!PolygonDetector::Silent()) 
        printf("Reading SVG file '%s'...", filename);

	// read file
	TiXmlDocument doc( filename );

	bool result = doc.LoadFile();

	if (!result) {
        printf("Failed to read SVG file '%s'", filename);
		return false;
 	}

	TiXmlElement* root = doc.FirstChildElement( "svg" );
	if ( !root ) {
        printf("The file %s is not a valid SVG file.");
		return false;
	}

	Line line;

	for(TiXmlElement* line_element = root->FirstChildElement("line");
		line_element;
		line_element = line_element->NextSiblingElement("line") )
	{
		
		const char * x1_s= line_element->Attribute("x1");
		const char * y1_s= line_element->Attribute("y1");
		const char * x2_s= line_element->Attribute("x2");
		const char * y2_s= line_element->Attribute("y2");

		if (!x1_s || !x2_s || !y1_s || !y2_s) {
			wxLogWarning("Failed to read line from SVG file.");
			continue;
		}

		float x1 = atof(x1_s); 
		float y1 = atof(y1_s);
		float x2 = atof(x2_s);
		float y2 = atof(y2_s);

		AddLine(x1,y1,x2,y2);	
	}

	if (!PolygonDetector::Silent())
        printf("SVG file read successfully. Created set with %d lines", GetLineCount());

	return true;
}

/**
* @descr Adds a line to the current line set
*/
void PolygonDetection::PolygonDetector::AddLine(double x1, double y1, double x2, double y2)
{
	_line_set.Add(new Line(x1, y1, x2, y2));
}

/**
* @descr Resets line and polygon sets
*/
void PolygonDetection::PolygonDetector::Reset(void)
{
	_line_set.Clear();
	_polygon_set.Clear();
}

/**
* @descr Performs polygon detection
*/
bool PolygonDetection::PolygonDetector::DetectPolygons(void)
{
    printf("Polygon detection");
	
	_interrupted = _time_exceeded = false;

	if (!PolygonDetector::Silent())
        printf("Line set contains %lld lines.", GetLineCount());

	_line_set.Normalize();
	
	if (!_line_set.RemoveIntersections()) {
        printf("Error: Could not successfully remove line intersections.");
		return false;
	}

	if (!PolygonDetector::Silent())
        printf("After removal, line set contains %lld lines.", GetLineCount());

	_line_set.Sort();

	if (!_polygon_set.Construct(&_line_set)) {
        printf("Error constructing the polygon set.");
		return false;
	} 

	if (!PolygonDetector::Silent())
        printf("Polygon set contains %d polygons.", _polygon_set.GetCount());

//	//ENDING_PROCESS_MESSAGE();
	return true;
}


bool PolygonDetection::PolygonDetector::CreateSVGwithPolygons(const wxString & filename) {

	FILE * fp = fopen(filename,"w");

	if (!fp) {
        printf("Could not create SVG file '%s'!",filename);
		return false;
	} 

	if (!PolygonDetector::Silent())
        printf("Creating SVG file '%s' with detected polygons.", filename);

	if (!fprintf(fp, _polygon_set.AsSVG(true).c_str())) {
        printf("Could not write SVG contents in specified file.");
		fclose(fp);
		return false;
	}

	fclose(fp);
	return true;
}

