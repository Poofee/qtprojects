#if !defined(AFX_GRAPH_H_INCLUDED)
#define AFX_GRAPH_H_INCLUDED

#define MAX_VERTICES 65535

#include "CycleSet.h"
#include "MatrixModuloTwo.h"

//#include <wx/datetime.h>

namespace PolygonDetection {

	class Graph  
	{
	public:
		CycleSet * Horton();
		void FloydWarshall();		
		void SetAdjacency(size_t v1, size_t v2);
		Graph(size_t vertices);
		virtual ~Graph();
		
		size_t GetEdgeCount();
		inline size_t GetVertexCount() { return _vertex_count; } ;

#ifdef GRAPH_DEBUG
		void Log();
#endif

	private:
		bool isAdjacent(size_t v1, size_t v2);

		bool IsTiermanCompliant(size_t v, wxArrayInt * path_vx, wxArrayInt * path_vy);
		bool IsOnlyCommonPointInPaths(size_t v, wxArrayInt * p1, wxArrayInt * p2);
		
		void InitializeFloydWarshall();	
		size_t MatrixOffset(size_t v1, size_t v2);
		size_t _vertex_count;
		MatrixModuloTwo * _p_adjacency_matrix;		
		
		wxArrayInt * GetShortestPath(size_t i, size_t j);	
		size_t * _d_matrix;
		size_t * _predecessor_matrix;

	};
}

#endif // !defined(AFX_GRAPH_H_INCLUDED)
