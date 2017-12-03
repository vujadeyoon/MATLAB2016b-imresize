/*
Editor : Sung-Jun Yoon
E-mail : sungjunyoon@kaist.ac.kr
Title : header.h
Version : 1701241333
*/

typedef struct byte_matrix_size {
	BYTE **buf;
	size_t row;
	size_t col;
} byte_buffer;

typedef struct double_matrix_size {
	double **buf;
	size_t row;
	size_t col;
} double_buffer;

typedef struct int_matrix_size {
	int **buf;
	size_t row;
	size_t col;
} int_buffer;

typedef struct double_3d_matrix_size {
	double ***buf;
	size_t row;
	size_t col;
	size_t page;
} double_buffer3;

typedef struct int_3d_matrix_size {
	int ***buf;
	size_t row;
	size_t col;
	size_t page;
} int_buffer3;

byte_buffer UC_mem_alloc_2_with_size(size_t row, size_t col, BYTE Initail_value);
int_buffer INT_mem_alloc_2_with_size(size_t row, size_t col, int Initail_value);
double_buffer DB_mem_alloc_2_with_size(size_t row, size_t col);
int_buffer3 INT_mem_alloc_3_with_size(size_t row, size_t col, size_t page);
double_buffer3 DB_mem_alloc_3_with_size(size_t row, size_t col, size_t page);
void UC_mem_cpy_2(BYTE **Ptr_dest, BYTE **Ptr_src, size_t row, size_t col);
void DB_mem_cpy_2(double **Ptr_dest, double **Ptr_src, size_t row, size_t col);
void INT_mem_cpy_3to2(int **Ptr_dest, int ***Ptr_src, size_t row, size_t col, size_t page);
void DB_mem_cpy_3to2(double **Ptr_dest, double ***Ptr_src, size_t row, size_t col, size_t page);
void free_mem_alloc_2(void **dest_buf, size_t row);

void print_UC_mem_alloc_2(byte_buffer *ptr_byte_buffer);
void print_DB_mem_alloc_2(double_buffer *ptr_double_buffer);