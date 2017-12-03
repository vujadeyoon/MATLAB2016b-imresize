/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: DB_mem_alloc_2_with_size.c
Version: 171203a
Description: 2D double memory allocation function with initializing 0
**************************************/

#include "header.h"

double_buffer DB_mem_alloc_2_with_size(size_t row, size_t col)
{
	// Initialize array with 0 using calloc function because memset function doesn't work for double array
	size_t i = 0;
	double_buffer res;
	res.row = row;
	res.col = col;
	
	res.buf = (double **)calloc(res.row, sizeof(double*));
	for (i = 0; i<res.row; i++) {
		res.buf[i] = (double *)calloc(res.col, sizeof(double));
	}

	return res;
}