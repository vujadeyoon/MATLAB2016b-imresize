/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: imresize.c
Version: 171203a
Description: imresize function supporting interpolation kernels as belows.
			 If you want some details about interpolation kernels, please refer the interp_kernel_func.c in this projects.
			 1) nearest (nearest neihborhood)
			 2) bilinear
			 3) bicubic
			 4) lanczos2
			 5) lanczos3			 
**************************************/

#include "header.h"

double_buffer imresize(double_buffer *ptr_ori, img_sz *ptr_out_img_sz, interp_kernel interp_kernel_name, bool anti_aliasing_filter)
{
	interp_kernel_taps kernel_taps;
	option_size pad_sz;
	scaling_ratio scaling_ratio_val;
	size_t kernel_tap = 0;
	size_t i, j, n = 0;
	size_t ori_interp_kernel_taps = 0;
	int idx_window = 0;
	int left = 0;
	int indices = 0;
	double idx_src = 0.0;
	double *window;
	double_buffer temp_pad;	
	double_buffer res_temp = DB_mem_alloc_2_with_size(ptr_ori->row, ptr_out_img_sz->col);
	double_buffer res = DB_mem_alloc_2_with_size(ptr_out_img_sz->row, ptr_out_img_sz->col);
	
	scaling_ratio_val.row = (double)ptr_out_img_sz->row / (double)ptr_ori->row;
	scaling_ratio_val.col = (double)ptr_out_img_sz->col / (double)ptr_ori->col;

	switch (interp_kernel_name) {
	case nearest:
		ori_interp_kernel_taps = 1;
		break;
	case bilinear:
		ori_interp_kernel_taps = 2;
		break;
	case bicubic:
		ori_interp_kernel_taps = 4;
		break;
	case lanczos2:
		ori_interp_kernel_taps = 4;
		break;
	case lanczos3:
		ori_interp_kernel_taps = 6;
		break;
	default:
		break;
	}

	kernel_taps.row = (double)ori_interp_kernel_taps;
	kernel_taps.col = (double)ori_interp_kernel_taps;

	if (scaling_ratio_val.col >= 1.0 || interp_kernel_name == nearest) {
		anti_aliasing_filter = false;
	}
	if (anti_aliasing_filter && (scaling_ratio_val.col < 1.0)) {
		kernel_taps.col /= scaling_ratio_val.col;
	}
	
	pad_sz.row = 0;
	pad_sz.col = (size_t) ceil((double)kernel_taps.col / 2.0);
	temp_pad = DB_padarray(ptr_ori, &pad_sz, symmetric);

	kernel_tap = (size_t)ceil(kernel_taps.col);
	window = (double *)calloc(kernel_tap, sizeof(double));

	for (i = 0; i<ptr_ori->row; i++) {
		for (j = 0; j<ptr_out_img_sz->col; j++) {
			idx_src = ((double)(j + 1) / scaling_ratio_val.col) + 0.5 * (1.0 - 1.0 / scaling_ratio_val.col); // u
			left = (int)floor(idx_src - ((double)kernel_taps.col / 2.0));
			indices = left - 1;
			
			for (n = 0; n < kernel_tap; n++) {
				idx_window = (left + (int)n) + (int)pad_sz.col;
				window[n] = temp_pad.buf[i][idx_window];
			}
			res_temp.buf[i][j] = iminterp1(window, (idx_src - indices - 1), scaling_ratio_val.col, interp_kernel_name, kernel_taps.col, anti_aliasing_filter); //idx_src - floor(idx_src)
		}
	}

	if (scaling_ratio_val.row >= 1.0 || interp_kernel_name == nearest) {
		anti_aliasing_filter = false;
	}
	if (anti_aliasing_filter && (scaling_ratio_val.row < 1.0)) {
		kernel_taps.row /= scaling_ratio_val.row;
	}

	pad_sz.row = (size_t)ceil((double)kernel_taps.row / 2.0);
	pad_sz.col = 0;
	temp_pad = DB_padarray(&res_temp, &pad_sz, symmetric);
	
	kernel_tap = (size_t)ceil(kernel_taps.row);
	window = (double *)calloc(kernel_tap, sizeof(double));	

	for (i = 0; i < ptr_out_img_sz->row; i++) {
		idx_src = ((double)(i + 1) / scaling_ratio_val.row) + 0.5 * (1.0 - 1.0 / scaling_ratio_val.row); // u
		left = (int)floor(idx_src - ((double)kernel_taps.row / 2.0));
		indices = left - 1;

		for (j = 0; j<ptr_out_img_sz->col; j++) {
			for (n = 0; n < kernel_tap; n++) {
				idx_window = (left + (int)n) + (int)pad_sz.row;
				window[n] = temp_pad.buf[idx_window][j];
			}
			res.buf[i][j] = iminterp1(window, (idx_src - indices - 1), scaling_ratio_val.row, interp_kernel_name, kernel_taps.row, anti_aliasing_filter);
		}
	}

	free(window);
	free_mem_alloc_2(temp_pad.buf, temp_pad.row);
	free_mem_alloc_2(res_temp.buf, res_temp.row);

	return res;	
}