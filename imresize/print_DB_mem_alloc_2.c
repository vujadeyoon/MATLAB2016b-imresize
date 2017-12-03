/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: imresize.c
Version: 171203a
Description: Print the given 2D double memory 
**************************************/

#include "header.h"

void print_DB_mem_alloc_2(double_buffer *ptr_double_buffer)
{
	size_t i, j = 0;
	
	for (i = 0; i < ptr_double_buffer->row; i++) {
		for (j = 0; j < ptr_double_buffer->col; j++) {
			printf("%.2f\t", ptr_double_buffer->buf[i][j]);
		}
		printf("\n");
	}
}