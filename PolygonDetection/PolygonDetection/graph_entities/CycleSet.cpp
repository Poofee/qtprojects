#include "CycleSet.h"

#include "../PDMacros.h"

#ifdef GRAPH_DEBUG	
#include <wx/log.h>
#endif

#include "IncidenceMatrix.h"

#include <stdlib.h> // for malloc and free
#include <malloc.h> // for malloc and free

using namespace PolygonDetection;

WX_DEFINE_OBJARRAY(CyclesArray);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/***
* @desc contructor
*/
CycleSet::CycleSet() : 
_p_cycles_array(nullptr)
{	
}

CycleSet::~CycleSet()
{	
	if (_p_cycles_array)
		WX_CLEAR_ARRAY(*_p_cycles_array);
	DELETE_ARRAY(_p_cycles_array);
}


void CycleSet::AddCycle(Cycle *c)
{
	if (!_p_cycles_array)
		//_p_cycles_array = new CyclesArray(Cycle::CompareOrder);
		_p_cycles_array = new CyclesArray();

	if (c)
		_p_cycles_array->Add(c);
}

#ifdef GRAPH_DEBUG	
/***
* @desc log cycles
*/
void CycleSet::Log()
{

	wxString s = "\n-------\nCycles:\n--------\n";	
		
	if (_p_cycles_array) 
		for (size_t j=0; j<_p_cycles_array->GetCount();j++) {
			Cycle * cycle = _p_cycles_array->Item(j);

			for (size_t i=0; i<cycle->GetVertexCount(); i++) 
				s += wxString::Format("->%d", cycle->GetVertex(i));
			
			s += "\n (Edges: ";	

			for (i=0; i<cycle->GetEdgeCount(); i++) 
				s += wxString::Format("-%d", cycle->GetEdge(i));
			
			s += ")\n";	
		}

	printf(s);
}
#endif


/***
* @return the number of cycles existing in this cycle set
*/
size_t CycleSet::GetCount()
{
	return _p_cycles_array?_p_cycles_array->GetCount():0;
}

/***
* @return the cycle at the position indicated, nullptr if does not exists
*/
Cycle * CycleSet::GetCycle(size_t number)
{
	if (_p_cycles_array && _p_cycles_array->GetCount()>number)
		return _p_cycles_array->Item(number);

	return nullptr;
}

/***
* @desc Select independent cycles from cycle set
*/
void CycleSet::SelectCycles()
{
	size_t c;
	bool independent_cycle;

	// creation of incidence matrix 
	IncidenceMatrix * incidence_matrix = new IncidenceMatrix();

	for (c=0; c<GetCount();c++) 
		incidence_matrix->AddCycleToEdgePool(_p_cycles_array->Item(c));

	incidence_matrix->CreateMatrix();

	for (c=0; c<GetCount();)  {		
		independent_cycle = incidence_matrix->IndependentCycle(_p_cycles_array->Item(c));
		
		if (!independent_cycle) {
			Cycle * cycle = _p_cycles_array->Item(c);
			_p_cycles_array->RemoveAt(c);		
			DELETE_OBJECT(cycle);
		}
		else 
			c++;
	}

#ifdef GRAPH_DEBUG	
	incidence_matrix->Log();
#endif	

	DELETE_OBJECT(incidence_matrix);
}


void CycleSet::Sort()
{
	if (_p_cycles_array)
		_p_cycles_array->Sort(Cycle::CompareOrder);
}
