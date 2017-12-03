/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: iminterp1.c
Version: 171203a
Description: 1D interpolation filter
**************************************/

#include "header.h"

double iminterp1(double *ptr_window, double idx_fraction, double scaling_ratio, interp_kernel interp_kernel_name, double interp_kernel_taps, bool anti_aliasing_filter)
{
	size_t i = 0;
	size_t kernel_taps = (size_t)ceil(interp_kernel_taps);
	double *interp_kernel_window = (double *)calloc(kernel_taps, sizeof(double));
	double cum_sum_interp_kernel_window = 0.0;
	double interesting_pst = 0.0;
	double initial_pst = 0.0;
	double res = 0.0;

	initial_pst = (idx_fraction - 1.0);
	for (i = 0; i < kernel_taps; i++) {
		interesting_pst = initial_pst - (double)i;
		
		if (anti_aliasing_filter) {
			interesting_pst *= scaling_ratio;
		}
		interp_kernel_window[i] = interp_kernel_func(interesting_pst, interp_kernel_name);
		if (anti_aliasing_filter) {
			interp_kernel_window[i] *= scaling_ratio;
		}
		cum_sum_interp_kernel_window += interp_kernel_window[i];
	}
	
	for (i = 0; i < kernel_taps; i++) {
		res += ptr_window[i] * (interp_kernel_window[i] / cum_sum_interp_kernel_window);
	}

	free(interp_kernel_window);

	return res;
}
