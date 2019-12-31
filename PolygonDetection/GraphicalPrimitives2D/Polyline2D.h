/*
+--------------------------------------------------------------------+
| Polyline2D.h: interface for the Polyline2D class.                  |
+--------------------------------------------------------------------+
|                                                                    |
| Author : Alfredo Ferreira Jr.                                      |
| E-mail : alfredo.ferreira.jr@inesc-id.pt                           |
| Website: http://immi.inesc-id.pt/~afj                              |
|                                                                    |
| Version: 1.01                                                      |
| Created: Jan 2003                                                  |
| Updated: May-Jun 2003                                              |
| Updated: Apr 2004 (Added DistanceTo and Extension methods)         |
| Updated: Feb 2008 (Peeled to basic functionalities)                |
|                                                                    |
+--------------------------------------------------------------------+
| Intelligent Multimodal Interfaces Group at INESC-ID                |
| Department of Information Systems and Computer Science             |
| IST/Technical University of Lisbon                                 |
| Rua Alves Redol 9                                                  |
| 100-029 Lisboa, Portugal                                           |
+--------------------------------------------------------------------+
|                                                                    |
| Copyright (c) 2003-2008 INESC-ID                                   |
|                                                                    |
|   The copyright to the computer program(s) herein is the property  |
| of INESC-ID, Portugal. The program(s) may be used and/or copied    |
| only with the written permission of INESC-ID or in accordance with |
| the terms and conditions stipulated in the agreement/contract      |
| under which the program(s) have been supplied.                     |
|                                                                    |
+--------------------------------------------------------------------+
*/
#pragma once

#if !defined(POLYLINE2D_H)
#define POLYLINE2D_H

#include "Box2D.h"	
#include "Point2D.h"
#include "Line2D.h"

#include "./GPConsts.h"

namespace GraphicalPrimitives2D {
	class Polygon2D; // to allow returning polygons inside polyline class

	class Polyline2D : public Entity2D
	{
	public:	
		bool Intersects(Polyline2D * polyline);
		bool Intersects(Entity2D * entity);

		PointArray * IntersectionPoints(Line2D *line, wxArrayInt * indexes = nullptr);
		bool Intersects(Line2D * line, bool proper = false);
		Point2D * Extension(double length, short flag = AT_END);
		double DistanceTo(Point2D * point, Point2D * nearest_point = nullptr, size_t * pred=nullptr, size_t * succ=nullptr);
		int Intersections();
		wxString AsString(bool svg_format=false, const wxString & stroke_color=DEFAULT_POLYLINE_COLOR, const wxString & fill_color=DEFAULT_POLYLINE_FILL);
		virtual void Rotate(double theta);
		virtual void Translate(double dx, double dy);
		virtual void Scale(double sx, double sy);
		
		bool HaveVertex(Point2D *p, size_t *index=nullptr);
		void Simplify(double tolerance);
		void VertexReduction(double tolerance);
		inline Point2D * GetVertexAt(size_t n) { return (n<_vertex_array.GetCount())?_vertex_array[n]:nullptr; };
		Point2D * GetVertexAt(size_t index, short offset);
		void Simplify();
		virtual void PerformRounding(double gamma);
		static Polyline2D * Join(Polyline2D *polyline1, Polyline2D *polyline2);
		void AddPolyline( Polyline2D * pl);
		Point2D * PointAt(double x, double y);
		Point2D * GetOtherPoint( Point2D *p );
//		static bool CoincidentExtremities(Polyline2D * polyline1, Polyline2D * polyline2);
		Point2D * GetLastVertex() { return _vertex_array.Last(); };
		Point2D * GetFirstVertex() { return _vertex_array[0]; };
		inline size_t GetVertexCount() { return _vertex_array.GetCount(); };
		inline PointArray * GetVertexArray() { return &_vertex_array; };
		virtual void CalculateFirstAndLastPoint();
		
		inline bool IsClosed() { return _closed; } ;
		inline double GetLength() { return _length; } ;
		virtual bool AddVertex(Point2D *vertex, short flag = AT_END, size_t pos = 0u);
		inline void SetClosed(bool closed) { _closed = closed; };

		inline virtual Point2D * GetStartPoint() { return (Point2D::Ordered(_vertex_array[0], _vertex_array.Last())?_vertex_array[0]:_vertex_array.Last()); };
		inline virtual Point2D * GetEndPoint() { return (Point2D::Ordered(_vertex_array[0], _vertex_array.Last())?_vertex_array.Last():_vertex_array[0]); };

		Polyline2D();
		Polyline2D(Line2D * line);
		Polyline2D(Polyline2D * polyline);
		virtual ~Polyline2D();

	protected:
		Polyline2D(entity_type type );

		void RecalculateLength();
		static bool HaveCommonVertex(Polyline2D *p1, Polyline2D *p2, size_t *i, size_t *j);
		virtual void CalculateBoundingBox();
		bool _closed;
		PointArray _vertex_array;

	private:	
		void DouglasPeucker(double tolerance, size_t start_index, size_t end_index);
		void ExecuteJoin(Polyline2D * pl, short flags = (NORMAL_ORDER | AT_END));
		double _length;
	};
}


#endif // !defined(POLYLINE2D_H)
