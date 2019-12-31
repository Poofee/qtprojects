#pragma once

#include "Line.h"
//#include <wx/dynarray.h>

namespace PolygonDetection {

//	WX_DECLARE_OBJARRAY(Line*, LinesArray);

	class LineSet
	{
	public:
		LineSet(void);
		~LineSet(void);

		void Add(Line * line);
        inline size_t GetCount() { return _lines_array.GetCount();}
        inline Line * Item(size_t i) {return _lines_array.Item(i);}

		bool RemoveIntersections(void);		

		void Clear(void);
		bool Normalize(void);
		void Sort(void);

	private:
		void RemoveZeroLengthLines(void);
		void RemoveOverlappings(void);
		void CalculateLinesFirstAndLastPoint(void);
		unsigned int DetectIntersections(void);

		LinesArray _lines_array;

		// Performs a scale transformation on lines of this set
		void Scale(double sx, double sy);

		// Performs a translation transformation on lines of this set
		void Translate(double dx, double dy);
	};
}
