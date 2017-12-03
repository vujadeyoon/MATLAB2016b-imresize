/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Dvelopement environment: MS Visual Studio 2017
Title: main.c
Version: 171203a
Description: implementation of MATLAB built-in function of imresize.
			 When down-scaling, anti-aliasing filter should be passed before reszing.
			 The anti-aliasing filter option is decided as the 4th parameter of imresize function.
			 For reference, the nearest neighborhood interpollation kernel is not supported for the anti-alising.
**************************************/

#include "header.h"

int main()
{
	img_sz out_img_sz_zoom; // The size of output image array for zooming
	img_sz out_img_sz_down;	// The size of output image array for down-scaling

	double_buffer ori = DB_mem_alloc_2_with_size(7, 7); // The input image array
	double_buffer out_zoom; // The output image array for zooming
	double_buffer out_down;	// The output image array for down-scaling
		
	/* Initialize the input image array */
	ori.buf[0][0] = 30.0; ori.buf[0][1] = 39.0; ori.buf[0][2] = 48.0; ori.buf[0][3] = 1.0; ori.buf[0][4] = 10.0; ori.buf[0][5] = 19.0; ori.buf[0][6] = 28.0;
	ori.buf[1][0] = 38.0; ori.buf[1][1] = 47.0; ori.buf[1][2] = 7.0; ori.buf[1][3] = 9.0; ori.buf[1][4] = 18.0; ori.buf[1][5] = 27.0; ori.buf[1][6] = 29.0;
	ori.buf[2][0] = 46.0; ori.buf[2][1] = 6.0; ori.buf[2][2] = 8.0; ori.buf[2][3] = 17.0; ori.buf[2][4] = 26.0; ori.buf[2][5] = 35.0; ori.buf[2][6] = 37.0;
	ori.buf[3][0] = 5.0; ori.buf[3][1] = 14.0; ori.buf[3][2] = 16.0; ori.buf[3][3] = 25.0; ori.buf[3][4] = 34.0; ori.buf[3][5] = 36.0; ori.buf[3][6] = 45.0;
	ori.buf[4][0] = 13.0; ori.buf[4][1] = 15.0; ori.buf[4][2] = 24.0; ori.buf[4][3] = 33.0; ori.buf[4][4] = 42.0; ori.buf[4][5] = 44.0; ori.buf[4][6] = 4.0;
	ori.buf[5][0] = 21.0; ori.buf[5][1] = 23.0; ori.buf[5][2] = 32.0; ori.buf[5][3] = 41.0; ori.buf[5][4] = 43.0; ori.buf[5][5] = 3.0; ori.buf[5][6] = 12.0;
	ori.buf[6][0] = 22.0; ori.buf[6][1] = 31.0; ori.buf[6][2] = 40.0; ori.buf[6][3] = 49.0; ori.buf[6][4] = 2.0; ori.buf[6][5] = 11.0; ori.buf[6][6] = 20.0;
	
	out_img_sz_zoom.row = 9;
	out_img_sz_zoom.col = 9;

	out_img_sz_down.row = 7;
	out_img_sz_down.col = 7;

	/*
	Uncomment the given code lines which you are interest in.
	out_zoom = imresize(&ori, &out_img_sz_zoom, nearest, true);	  // Nearest neighborhood, Zoom, Anti-aliasing option: true (should not be working because of zooming)
	out_down = imresize(&ori, &out_img_sz_down, nearest, true);   // Nearest neighborhood, Down-scaling, Anti-aliasing option: true (should not be working because of 'nearest' option)
	out_zoom = imresize(&ori, &out_img_sz_zoom, bilinear, false); // Bilinear, Zoom, Anti-aliasing option: false
	out_down = imresize(&ori, &out_img_sz_down, bilinear, false); // Bilinear, Down-scaling, Anti-aliasing option: false
	out_zoom = imresize(&ori, &out_img_sz_zoom, bicubic, true);   // Bicubic, Zoom, Anti-aliasing option: true (should not be working because of zooming)
	out_down = imresize(&ori, &out_img_sz_down, bicubic, true);   // Bicubic, Down-scaling, Anti-aliasing option: true
	out_zoom = imresize(&ori, &out_img_sz_zoom, lanczos2, false); // Lanczos2, Zoom, Anti-aliasing option: false
	out_down = imresize(&ori, &out_img_sz_down, lanczos2, true);  // Lanczos2, Down-scaling, Anti-aliasing option: true
	out_zoom = imresize(&ori, &out_img_sz_zoom, lanczos3, false); // Lanczos3, Zoom, Anti-aliasing option: false
	out_down = imresize(&ori, &out_img_sz_down, lanczos3, true);  // Lanczos3, Down-scaling, Anti-aliasing option: ture
	*/

	out_zoom = imresize(&ori, &out_img_sz_zoom, bicubic, true);   // Bicubic, Zoom, Anti-aliasing option: true (should not be working because of zooming)
	out_down = imresize(&ori, &out_img_sz_down, bicubic, true);   // Bicubic, Down-scaling, Anti-aliasing option: true
		
	printf("Original input image array\n");
	print_DB_mem_alloc_2(&ori);

	printf("\nZoomed image array\n");
	print_DB_mem_alloc_2(&out_zoom);

	printf("\nDown-scaled image array\n");
	print_DB_mem_alloc_2(&out_down);
	
	free_mem_alloc_2(ori.buf, ori.row);
	free_mem_alloc_2(out_zoom.buf, out_zoom.row);
	free_mem_alloc_2(out_down.buf, out_down.row);

	return 0;
}