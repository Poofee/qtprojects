#pragma once

#include "./Polygon.h"
#include "./graph_entities/Graph.h"
#include "LineSet.h"

namespace PolygonDetection {

	WX_DECLARE_OBJARRAY(Polygon*, PolygonsArray);

	class PolygonSet
	{
	public:
		PolygonSet(void);
		~PolygonSet(void);
		// Constructs a polygon set from given line set
		bool Construct(LineSet * line_set);

		// Simplifies the polygon set
		void Simplify(double smaller_polygon_length);

		inline size_t GetCount() { return _polygons_array.GetCount(); };
		inline Polygon * Item(size_t i) { return _polygons_array.Item(i); };

		void Clear(void);

	private:
		void CreatePointsArray(LineSet * line_set);
		Graph * LinesToGraph(LineSet * line_set);
		void CyclesToPolygons(CycleSet * cycle_set);

		size_t GetPointCount();
		GraphicalPrimitives2D::Point2D * PointByID(size_t id);

		GraphicalPrimitives2D::PointArray _all_points_array;
		PolygonsArray _polygons_array;

	public:
		// Returns a string with the SVG containing the polygon set
		wxString AsSVG(bool colorized=false);
	};
}
