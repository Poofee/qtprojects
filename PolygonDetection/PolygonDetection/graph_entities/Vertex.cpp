#include "Vertex.h"

#include "../PDMacros.h"

#include <stdlib.h> // for malloc and free
#include <malloc.h> // for malloc and free

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/***
* @desc contructor
*/
PolygonDetection::Vertex::Vertex(size_t id)
{	
	_id = id;	
}


PolygonDetection::Vertex::~Vertex()
{		
}

