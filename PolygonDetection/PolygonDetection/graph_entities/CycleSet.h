/*
+--------------------------------------------------------------------+
| CycleSet.h: interface for the CycleSet class.                      |
+--------------------------------------------------------------------+
|                                                                    |
| Author : Alfredo Ferreira Jr.                                      |
| E-mail : alfredo.ferreira.jr@inesc-id.pt                           |
| Website: http://immi.inesc-id.pt/~afj                              |
|                                                                    |
| Version: 1.00                                                      |
| Created: May 2003                                                  |
|                                                                    |
+--------------------------------------------------------------------+
| Intelligent Multimodal Interfaces Group at INESC-ID                |
| Department of Information Systems and Computer Science             |
| IST/Technical University of Lisbon                                 |
| Rua Alves Redol 9                                                  |
| 100-029 Lisboa, Portugal                                           |
+--------------------------------------------------------------------+
|                                                                    |
| Copyright (c) 2003 INESC-ID                                        |
|                                                                    |
|   The copyright to the computer program(s) herein is the property  |
| of INESC-ID, Portugal. The program(s) may be used and/or copied    |
| only with the written permission of INESC-ID or in accordance with |
| the terms and conditions stipulated in the agreement/contract      |
| under which the program(s) have been supplied.                     |
|                                                                    |
+--------------------------------------------------------------------+
*/
#if !defined(AFX_CYCLESET_H_INCLUDED)
#define AFX_CYCLESET_H_INCLUDED

#include "Cycle.h"

#include <wx/arrimpl.cpp> 

namespace PolygonDetection {
	WX_DECLARE_OBJARRAY(Cycle *, CyclesArray);

	class CycleSet
	{
	public:	
		void Sort();
		void SelectCycles();
		Cycle * GetCycle(size_t number);
		size_t GetCount();

		void AddCycle(Cycle * c);
		CycleSet();
		virtual ~CycleSet();

#ifdef GRAPH_DEBUG	
		void Log();
#endif

	private:
		CyclesArray * _p_cycles_array;
	};
}
#endif // !defined(AFX_CYCLESET_H_INCLUDED)
