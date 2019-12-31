/*
+--------------------------------------------------------------------+
| MatrixModuloTwo.h: interface for the MatrixModuloTwo class.        |
+--------------------------------------------------------------------+
|                                                                    |
| Author : Alfredo Ferreira Jr.                                      |
| E-mail : alfredo.ferreira.jr@inesc-id.pt                           |
| Website: http://immi.inesc-id.pt/~afj                              |
|                                                                    |
| Version: 1.00                                                      |
| Created: Jun 2003                                                  |
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
#if !defined(AFX_MATRIXMODULOTWO_H_INCLUDED)
#define AFX_MATRIXMODULOTWO_H_INCLUDED

namespace PolygonDetection {
	class MatrixModuloTwo
	{
	public:	
#ifdef GRAPH_DEBUG	
		void Log();
#endif

		void GaussianElimination(size_t rows);	

		inline __int8 Get(size_t base, size_t offset) { return _matrix[base+offset];}
		inline void Set(size_t base, size_t offset, __int8 value) {
			_matrix[base+offset] = value;
		}

		inline __int8 GetAt(size_t row, size_t col) { return _matrix[GetAddress(row,col)]; };
		inline void SetAt(size_t row, size_t col, __int8 value) { _matrix[GetAddress(row, col)] = value; };
		
		MatrixModuloTwo(size_t rows, size_t cols);
		virtual ~MatrixModuloTwo();

	private:
		void SwapMatrixRows(size_t row_a, size_t row_b);
		inline size_t GetAddress(size_t row, size_t col) { return row*_cols+col; };
		size_t _rows;
		size_t _cols;

		__int8 * _matrix;
	};
}
#endif // !defined(AFX_MATRIXMODULOTWO_H_INCLUDED)
