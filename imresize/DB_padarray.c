/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: DB_mem_alloc_2_with_size.c
Version: 171203a
Description: 2D double padding function
**************************************/

#include "header.h"

double_buffer DB_padarray(double_buffer *Ptr_ori_buf, option_size *Ptr_pad_pair_number, how_to_pad option)
{
	size_t i, j, k = 0;
	double_buffer res = DB_mem_alloc_2_with_size(Ptr_ori_buf->row + 2 * Ptr_pad_pair_number->row, Ptr_ori_buf->col + 2 * Ptr_pad_pair_number->col);

	switch (option) {
	case replicate: // replicate, mirroring
		for (i = 0; i < Ptr_ori_buf->row; i++) {
			memcpy(res.buf[i + Ptr_pad_pair_number->row] + Ptr_pad_pair_number->col, Ptr_ori_buf->buf[i], Ptr_ori_buf->col*sizeof(double));
		}

		for (i = 0; i < Ptr_pad_pair_number->row; i++) {
			memcpy(res.buf[i], res.buf[Ptr_pad_pair_number->row], res.col*sizeof(double));
			memcpy(res.buf[i + Ptr_ori_buf->row + Ptr_pad_pair_number->row], res.buf[Ptr_ori_buf->row + Ptr_pad_pair_number->row - 1], res.col*sizeof(double));
		}

		for (j = 0; j < Ptr_pad_pair_number->col; j++) {
			for (i = 0; i < res.row; i++) {
				res.buf[i][j] = res.buf[i][Ptr_pad_pair_number->col];
				res.buf[i][j + Ptr_ori_buf->col + Ptr_pad_pair_number->col] = res.buf[i][Ptr_ori_buf->col + Ptr_pad_pair_number->col - 1];
			}
		}
		break;

	case symmetric:
		for (i = 0; i < Ptr_ori_buf->row; i++) {
			memcpy(res.buf[i + Ptr_pad_pair_number->row] + Ptr_pad_pair_number->col, Ptr_ori_buf->buf[i], Ptr_ori_buf->col*sizeof(double));
		}

		for (i = Ptr_pad_pair_number->row, j = 0; i >= 1; i--, j += 2) {
			memcpy(res.buf[i - 1], res.buf[i + j], res.col*sizeof(double));
			memcpy(res.buf[res.row - i], res.buf[i + Ptr_ori_buf->row - 1], res.col*sizeof(double));
		}

		for (j = Ptr_pad_pair_number->col, k = 0; j >= 1; j--, k += 2) {
			for (i = 0; i < res.row; i++) {
				res.buf[i][j - 1] = res.buf[i][j + k];
				res.buf[i][res.col - j] = res.buf[i][j + Ptr_ori_buf->col - 1];
			}
		}
		break;

	case circular: // @To do
		error("The option of padarray function has not been implemented yet");
		break;

	default:
		printf("The option of padarray function is not correct.\n");
		assert(option != 's');
	}

	return res;
}