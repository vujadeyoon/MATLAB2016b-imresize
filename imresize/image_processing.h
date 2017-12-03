/*
Editor : Sung-Jun Yoon
E-mail : sungjunyoon@kaist.ac.kr
Title : header.h
Version : 1701241333
*/

#define NumOfBit 8
#define MAX_INT pow(2, NumOfBit) - 1 // 2^8-1

typedef unsigned char BYTE;

typedef struct {
	size_t row;
	size_t col;
	byte_buffer buf_B;
	byte_buffer buf_G;
	byte_buffer buf_R;
} picture_BMP;

typedef struct {
	size_t row;
	size_t col;
} option_size;

typedef struct {
	size_t row;
	size_t col;
} img_sz;

typedef struct {
	double row;
	double col;
} scaling_ratio;

typedef struct {
	double row;
	double col;
} interp_kernel_taps;

typedef enum {
	nearest, 
	bilinear, 
	bicubic,
	lanczos2, 
	lanczos3
} interp_kernel;

typedef enum {
	circular,
	replicate,
	symmetric
} how_to_pad;

//double_buffer UC2DB(byte_buffer *Ptr_ori);
//int ROUND(double temp);
//BYTE CLMP(int temp);
//
//picture_BMP imread(char *filename);
//void imwrite(picture_BMP *ori_bmp, const char* filename, const char* fileformat);
byte_buffer UC_padarray(byte_buffer *Ptr_ori_buf, option_size *Ptr_pad_pair_number, how_to_pad option);
double_buffer DB_padarray(double_buffer *Ptr_ori_buf, option_size *Ptr_pad_pair_number, how_to_pad option);

//size_t validate_region(int temp, size_t region_boundary, how_to_pad option);

double iminterp1(double *ptr_window, double idx_fraction, double scaling_ratio, interp_kernel interp_kernel_name, double interp_kernel_taps, bool anti_aliasing_filter);
double_buffer imresize(double_buffer *ptr_ori, img_sz *ptr_out_img_sz, interp_kernel interp_kernel_name, bool anti_aliasing_filter);
double interp_kernel_func(double x, interp_kernel interp_kernel_name);
