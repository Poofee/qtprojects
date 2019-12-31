/*
+--------------------------------------------------------------------+
| Entity2D.h: interface for the Entity2D class.                      |
+--------------------------------------------------------------------+
|                                                                    |
| Author : Alfredo Ferreira Jr.                                      |
| E-mail : alfredo.ferreira.jr@inesc-id.pt                           |
| Website: http://immi.inesc-id.pt/~afj                              |
|                                                                    |
| Version: 1.00                                                      |
| Created: Jan 2003                                                  |
| Updated: Jul-Aug 2003                                              |
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

#if !defined(ENTITY2D_H_INCLUDED)
#define ENTITY2D_H_INCLUDED

//#include <wx/string.h>
//#include <wx/dynarray.h>

namespace GraphicalPrimitives2D {
	// cannot include point2D or box2D
	class Point2D;
	class Box2D;

	class Entity2D  
	{
		
	public:		
        enum entity_type {
			et_point = 0,
			et_line,
			et_polyline,
			et_polygon,
			et_vector,
			et_box
		};
		
        virtual void Translate(double /*dx*/, double /*dy*/) {}
        virtual void Scale(double /*sx*/, double /*sy*/) {}
        virtual void Rotate(double /*theta*/) {}

//		static wxString Name(entity_type et);

        inline size_t GetID() { return _id; }
        inline void SetID(size_t id) { _id = id; }
		
//		virtual void PerformRounding(double) {};
//		inline bool IsLastPoint( Point2D * p );
//		inline bool IsFirstPoint( Point2D * p );

        inline entity_type GetType() { return _type; }
//		static int CompareOrder(Entity2D *** e1, Entity2D *** e2);
        virtual void CalculateFirstAndLastPoint() {}
		void RecalculateBoundingBox();
		Box2D  * GetBoundingBox();
	        
//		inline virtual Point2D * GetStartPoint() { return nullptr; };
//		inline virtual Point2D * GetEndPoint() { return nullptr; };

        inline Point2D * GetFirstPoint() { return _first_point; }
        inline Point2D * GetLastPoint() { return _last_point; }

		static double Area(Point2D *a, Point2D *b, Point2D *c);

        inline bool GetFlag(short mask) { return ((_flag & mask)!=0); }
        inline void SetFlag(short mask) { _flag |= mask; }
        inline void ResetFlag(short mask) { _flag &= (~ mask); }

		Entity2D(entity_type type);
		virtual ~Entity2D();

	private:
		entity_type _type;

		Point2D * _first_point; 
		Point2D * _last_point; 

		size_t _id;
		short _flag;

	protected:	
		Box2D * _p_bounding_box;
		
        virtual void CalculateBoundingBox() {}
		
        inline void SetFirstPoint(Point2D *p) { _first_point = p; }
        inline void SetLastPoint(Point2D *p) { _last_point = p; }
	};

//	WX_DECLARE_OBJARRAY(Entity2D*, EntityArray);
}
#endif 
