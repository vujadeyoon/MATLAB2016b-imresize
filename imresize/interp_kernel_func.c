/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: interp_kernel_func.c
Version: 171203a
Description: To interpolate a intermeidate pixel using the given interpolation kernel.
**************************************/

#include "header.h"

double interp_kernel_func(double x, interp_kernel interp_kernel_name)
{
	double res = 0.0;
	double absx = fabs(x);
	double absx2 = absx * absx;
	double absx3 = absx * absx2;

	switch (interp_kernel_name) {
	case nearest:
		res = ((-0.5 <= x) && (x < 0.5));
		break;
	case bilinear:
		res = (x + 1)*((-1 <= x) && (x < 0)) + (-x + 1)*((0 <= x) && (x <= 1));
		break;
	case bicubic:
		/* See Keys, "Cubic Convolution Interpolation for Digital Image
		   Processing, " IEEE Transactions on Acoustics, Speech, and Signal
		   Processing, Vol.ASSP - 29, No. 6, December 1981, p. 1155. */
		res = (1.5*absx3 - 2.5*absx2 + 1.0) * (absx <= 1) + (-0.5*absx3 + 2.5*absx2 - 4.0 * absx + 2.0) * ((1 < absx) && (absx <= 2));
		break;
	case lanczos2:
		/* See Graphics Gems, Andrew S.Glasser(ed), Morgan Kaufman, 1990,
		   pp. 156 - 157. */
		res = (sin(PI*x)*sin(PI*x / 2.0) + EPS) / (((pow(PI, 2.0) * pow(x, 2.0)) / 2.0) + EPS);
		res *= (absx < 2);
		break;
	case lanczos3:
		/* See Graphics Gems, Andrew S.Glasser(ed), Morgan Kaufman, 1990,
		   pp. 157 - 158. */
		res = (sin(PI*x)*sin(PI*x / 3.0) + EPS) / (((pow(PI, 2.0) * pow(x, 2.0)) / 3.0) + EPS);
		res *= (absx < 3);
		break;
	default:
		error("The function interp_kernel_func may be error.");
	}

	return res;
}
