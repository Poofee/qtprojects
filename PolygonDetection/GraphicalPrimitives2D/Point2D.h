/*
+--------------------------------------------------------------------+
| Point2D.h: interface for the Point2D class.                        |
+--------------------------------------------------------------------+
|                                                                    |
| Author : Alfredo Ferreira Jr.                                      |
| E-mail : alfredo.ferreira.jr@inesc-id.pt                           |
| Website: http://immi.inesc-id.pt/~afj                              |
|                                                                    |
| Version: 2.00                                                      |
| Created: Jan 2003                                                  |
| Updated: Jul-Sep 2003                                              |
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

#if !defined(POINT2D_H_INCLUDED)
#define POINT2D_H_INCLUDED

#include "Entity2D.h"

#define SCALE_2D(obj,s) { (obj)->Scale(s,s); }
#define POINT2D_AS_XY(p) ((GraphicalPrimitives2D::Point2D *)p)->GetX(), ((GraphicalPrimitives2D::Point2D *)p)->GetY()

//#include <wx/dynarray.h>

namespace GraphicalPrimitives2D {
	class Point2D : public Entity2D
	{
	public:
		static int CompareOrderUsingDistanceToOwner(Point2D ***p1, Point2D ***p2);
		virtual void Rotate(double theta);
		double SquareDistanceTo(Point2D *p);
		virtual void PerformRounding(double gamma);
		
		bool Between(Point2D *a, Point2D *b);
		bool StrictBetween(Point2D *a, Point2D *b);
		bool Left(Point2D * a, Point2D * b);
		bool Collinear(Point2D *a, Point2D *b);

		static bool Ordered(Point2D * p1, Point2D * p2);
		static int CompareOrder(Point2D * p1, Point2D * p2);
		
		// the next two methods are used to sort arrays
		static int CompareOrder(Point2D *** p_p1, Point2D *** p_p2);
		static int CompareOrder(Entity2D *** p_p1, Entity2D *** p_p2);

        inline Entity2D * GetOwnerEntity() { return _owner_entity;}
        inline void SetOwnerEntity(Entity2D * owner_entity) { _owner_entity = owner_entity;}

		virtual void CalculateFirstAndLastPoint();
		
		void Set(Point2D * p);

		double DistanceTo(Point2D * p);
		virtual void Translate(double dx,double dy);
		virtual void Scale(double sx, double sy);
		
        inline double GetX() { return _x; }
        inline double GetY() { return _y; }

        inline void SetX(double x) { _x=x; }
        inline void SetY(double y) { _y=y; }

		//inline size_t GetCoincidentPointsCount() { return _coincident_points_counter;};
		//inline size_t IncrementCoincidentPointsCount() { return (_coincident_points_counter++);};

        inline void SetIndex(size_t index) { _index=index; }
        inline size_t GetIndex() { return _index; }

		bool operator==(const Point2D &p);
		bool operator!=(const Point2D &p);

		void operator=(const Point2D &p);

		Point2D(void);
		Point2D(Point2D * p);
		Point2D(double x, double y);
		virtual ~Point2D();

	private:
		void Initialize(double x, double y);
		static void Round(double *value, double * gamma);
		Entity2D * _owner_entity;
		double _x;
		double _y;
		size_t _index;
//		size_t _coincident_points_counter;
	};

//	WX_DECLARE_OBJARRAY(Point2D*, PointArray);
}

#endif // !defined(POINT2D_H_INCLUDED)
