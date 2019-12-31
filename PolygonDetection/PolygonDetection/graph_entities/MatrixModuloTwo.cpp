#include <stdlib.h> // for malloc and free
#include <malloc.h> // for malloc and free
#include <memory.h> // for memset

//#include <wx/log.h>

#include "MatrixModuloTwo.h"
#include "../PDMacros.h"
#include "../PolygonDetector.h"

using namespace PolygonDetection;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/***
* @desc contructor
*/

MatrixModuloTwo::MatrixModuloTwo(size_t rows, size_t cols)
{	
	_rows = rows;
	_cols = cols;

	// create the matrix

	// first allocates memory
	size_t dim = _rows*_cols;
	_matrix = ALLOCATE_MEMORY(__int8, dim);

	// the reset memory to zero reserved memory
	memset(_matrix, 0, dim);	

	if (!PolygonDetector::Silent()) {
		unsigned long used_memory = sizeof(__int8)*dim;
		bool kbytes = false;
		if (used_memory>1024) {
			kbytes = true;
			used_memory /= 1024;
		}
		printf("Adjacency matrix uses %u %s.", used_memory, kbytes?"KB":"bytes");
	}
	
}


MatrixModuloTwo::~MatrixModuloTwo()
{		
	FREE(_matrix);
}



/***
* @desc swaps the matrix row <row_a> with row <row_b>
* @param size_t row_a indicates the number of one row  
* @param size_t row_b indicates the number of other row  
*/
void MatrixModuloTwo::SwapMatrixRows(size_t row_a, size_t row_b)
{
	__int8 t; // variable to store temporarily the value

	size_t row_a_offset = row_a*_cols;
	size_t row_b_offset = row_b*_cols;

	
	for (size_t k=0; k<_cols; k++) {
		t = _matrix[row_a_offset+k];
		_matrix[row_a_offset+k] = _matrix[row_b_offset+k];
		_matrix[row_b_offset+k] = t;
	}
}

/***
* @desc performs gaussian elimination of first <rows> of the matrix
*/
void MatrixModuloTwo::GaussianElimination(size_t rows)
{
	size_t c, r, k, max; //, address;

	size_t pivot_row=0;


		for(c=0;c<_cols;c++) {		
		max = pivot_row;

		// in this case no substitution is needed
		if (_matrix[pivot_row*_cols+c]!=0x01) {
		
			// otherwise, lets found if its needed any substitution
			for (r=pivot_row+1;r<rows;r++) {
				if (_matrix[r*_cols+c]==1) {
					max = r;
					break;
				}
			}

			// if pivot row is zero and other column is one
			// then they must change			
			if (max!=pivot_row)
				SwapMatrixRows(max,pivot_row);
		}

		// now lets make the elimination
		if (_matrix[pivot_row*_cols+c]==0x01) {
			for (r=pivot_row+1; r<rows; r++)
				if (_matrix[r*_cols+c]==0x01)
					for (k=c;k<_cols;k++)
						_matrix[r*_cols+k] ^= _matrix[pivot_row*_cols+k];

			pivot_row++;
		}
	}

}


#ifdef GRAPH_DEBUG	
void MatrixModuloTwo::Log()
{
	wxString s="";	

	for (size_t i=0; i<_rows;i++) {
		for(size_t j=0; j<_cols;j++)
			s += wxString::Format("%d ",_matrix[GetAddress(i,j)]);
		
		s += "\n";		
	}

	printf(s);

}
#endif
