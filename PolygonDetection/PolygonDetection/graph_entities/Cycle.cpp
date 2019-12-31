#include "Cycle.h"

#include "../PDMacros.h"

using namespace PolygonDetection;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/***
* @desc contructor
*/
Cycle::Cycle(wxArrayInt *path_vx, wxArrayInt *path_vy) : 
_p_cycle(nullptr),
_p_edge_list(nullptr),
_generated_from(0)
{		
	size_t i;
	size_t item_vx = path_vx->Item(0);
	size_t item_vy = path_vy->Item(0);


	// checks if both path start at 'v'
	if (item_vx == item_vy ) {	

		_generated_from = item_vx;

		// creates a new array
		_p_cycle = new wxArrayInt(/*path_vx->GetCount()+path_vy->GetCount()*/);

		for (i=0; i< path_vx->GetCount(); i++) {
			item_vx = path_vx->Item(i);
			_p_cycle->Add(item_vx);
		}


		for (i=1; i<= path_vy->GetCount(); i++) {
			item_vy = path_vy->Item(path_vy->GetCount()-i);
			_p_cycle->Add(item_vy);
		}

		_p_edge_list = new wxArrayInt();
	} 
}

Cycle::~Cycle()
{	
	DELETE_ARRAY(_p_cycle);
	DELETE_ARRAY(_p_edge_list);
}

/**
* @desc compares two cycles in term of order
* @return negative, zero or positive value 
*         according to whether the first element 
*         passed to it is less than, equal to or 
*         greater than the second one. 
*/
int Cycle::CompareOrder(Cycle *p_c1, Cycle *p_c2)
{
	if (p_c1->GetLength()==p_c2->GetLength()) {		
		return p_c1->_generated_from - p_c2->_generated_from;
	}

	return p_c1->GetLength() - p_c2->GetLength();
}

/***
* @return the vertex at position number
*/
//size_t Cycle::GetVertex(size_t number)
//{
//	return (_p_cycle && _p_cycle->GetCount()>number)?_p_cycle->Item(number):0;
//}

int Cycle::CompareOrder(Cycle ***p_c1, Cycle ***p_c2)
{
	return CompareOrder(**p_c1, **p_c2);
}
