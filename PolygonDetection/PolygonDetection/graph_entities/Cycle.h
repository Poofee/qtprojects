/*
+--------------------------------------------------------------------+
| Cycle.h: interface for the Cycle class.                            |
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
#if !defined(AFX_CYCLE_H_INCLUDED)
#define AFX_CYCLE_H_INCLUDED

#include <wx/dynarray.h>

namespace PolygonDetection {	

	class Cycle
	{
	public:
		static int CompareOrder(Cycle * p_c1, Cycle * p_c2);
		static int CompareOrder(Cycle ***p_c1, Cycle ***p_c2);

		void AddEdge(unsigned int edge_id) { if (_p_edge_list) _p_edge_list->Add(edge_id); };

		inline size_t GetVertex(size_t number) {
			return (_p_cycle && _p_cycle->GetCount()>number)?_p_cycle->Item(number):0;
		};	
		inline size_t GetEdge(size_t number) { 
			return (_p_edge_list && _p_edge_list->GetCount()>number)?_p_edge_list->Item(number):0;
		};

		inline size_t GetVertexCount() { return _p_cycle?_p_cycle->GetCount():0;};
		inline size_t GetEdgeCount() { return _p_edge_list?_p_edge_list->GetCount():0;};

		inline size_t GetLength() { return GetVertexCount(); };	

		Cycle(wxArrayInt *path_vx, wxArrayInt *path_vy);
		virtual ~Cycle();

	private:
		size_t _generated_from;
		wxArrayInt * _p_cycle;	
		wxArrayInt * _p_edge_list;
	};
}

#endif // !defined(AFX_CYCLE_H_INCLUDED)
