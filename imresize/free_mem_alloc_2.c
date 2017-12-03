/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: free_mem_alloc_2.c
Version: 171203a
Description: To free the 2D memory
**************************************/

#include "header.h"

void free_mem_alloc_2(void **dest_buf, size_t row) {
	size_t i = 0;

	for (i = 0; i < row; i++) {
		free(dest_buf[i]);
	}
	free(dest_buf);
}