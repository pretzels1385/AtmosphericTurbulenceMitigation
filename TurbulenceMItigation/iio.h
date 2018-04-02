#ifndef _IIO_H
#define _IIO_H

#include <stddef.h>
#include <stdbool.h>







float *iio_read_image_float(const char *fname, int *w, int *h);
// x[i+j*w]

float *iio_read_image_float_vec(const char *fname, int *w, int *h, int *pd);
// x[(i + j*w)*pd + l]

float *iio_read_image_float_rgb(const char *fname, int *w, int *h);

//
// convenience float API for 2D images (also returns a freeable pointer)
//

float **iio_read_image_float_matrix(const char *fname, int *w, int *h);
// x[j][i]

float (**iio_read_image_float_matrix_2vec(const char *fnam, int *w, int *h))[2];
float (**iio_read_image_float_matrix_3vec(const char *fnam, int *w, int *h))[3];
float (**iio_read_image_float_matrix_4vec(const char *fnam, int *w, int *h))[4];
float (**iio_read_image_float_matrix_rgb(const char *fnam, int *w, int *h))[3];
float (**iio_read_image_float_matrix_rgba(const char *fnam, int *w, int *h))[4];
// x[j][i][channel]
// (The "rgb" and "rgba" functions may re-order the channels according to file
// metadata.  The "vec" functions produce the data in the same order as is
// stored.)
void *iio_read_image_float_matrix_vec(const char *fnam, int *w, int *h, int *pd);




double *iio_read_image_double(const char *fname, int *w, int *h);
double *iio_read_image_double_vec(const char *fname, int *w, int *h, int *pd);

// All these functions are boring  variations, and they are defined at the
// end of this file.  More interesting are the two following general
// functions:

void *iio_read_image_numbers_as_they_are_stored(char *fname, int *w, int *h,
		int *samples_per_pixel, int *sample_size,
		bool *ieeefp_samples, bool *signed_samples);

void *iio_read_image_numbers_in_requested_format(char *fname, int *w, int *h,
		int *samples_per_pixel, int requested_sample_size,
		bool requested_ieeefp, bool requested_sign);

// These two general functions have the usual versions for nD images and
// streams.  There exist also the following truly general functions, that
// read images of any dimension:

void *iio_read_nd_image_as_stored(char *fname,
		int *dimension, int *sizes,
		int *samples_per_pixel, int *sample_size,
		bool *ieeefp_samples, bool *signed_samples);

void *iio_read_nd_image_as_desired(char *fname,
		int *dimension, int *sizes,
		int *samples_per_pixel, int desired_sample_size,
		bool desired_ieeefp_samples, bool desired_signed_samples);










#ifdef UINT8_MAX

// basic byte API (returns a freeable pointer)
//

uint8_t *iio_read_image_uint8(const char *fname, int *w, int *h);
// x[i+j*w]

uint8_t *iio_read_image_uint8_vec(const char *fname, int *w, int *h, int *nc);
// x[(i + j*w)*nc + l]
//
uint8_t (*iio_read_image_uint8_rgb(const char *fnam, int *w, int *h))[3];


//
// convenience float API (also returns a freeable pointer)
//

uint8_t **iio_read_image_uint8_matrix(const char *fname, int *w, int *h);
// x[j][i]

uint8_t (**iio_read_image_uint8_matrix_2vec(const char *fnam, int *w, int *h))[2];
uint8_t (**iio_read_image_uint8_matrix_3vec(const char *fnam, int *w, int *h))[3];
uint8_t (**iio_read_image_uint8_matrix_4vec(const char *fnam, int *w, int *h))[4];
uint8_t (**iio_read_image_uint8_matrix_rgb(const char *fnam, int *w, int *h))[3];
uint8_t (**iio_read_image_uint8_matrix_rgba(const char *fnam, int *w, int *h))[4];

uint8_t ***iio_read_image_uint8_matrix_vec(const char *fnam, int *w, int *h, int *pd);

// _4d versions, etc
// ...

#endif//UINT8_MAX

#ifdef UINT16_MAX
uint16_t *iio_read_image_uint16_vec(const char *fname, int *w, int *h, int *pd);
#endif//UINT16_MAX

//
// EDITABLE CONFIGURATION:
//
#define IIO_MAX_DIMENSION 5
//#define IIO_ABORT_ON_ERROR true
//
//
//

//
void *iio_read_image_raw(const char *fname,
		int *dimension,
		int sizes[IIO_MAX_DIMENSION],
		int *pixel_dimension,
		size_t *sample_integer_size,
		size_t *sample_float_size,
		int *metadata_id);






#include <stdint.h>

void iio_save_image_float_vec(char *filename, float *x, int w, int h, int pd);
void iio_save_image_double_vec(char *filename, double *x, int w, int h, int pd);
void iio_save_image_float(char *filename, float *x, int w, int h);
void iio_save_image_double(char *filename, double *x, int w, int h);
void iio_save_image_uint8_vec(char *filename, uint8_t *x, int w, int h, int pd);
void iio_save_image_uint16_vec(char *filename, uint16_t *x, int w, int h, int pd);
void iio_save_image_uint8_matrix_rgb(char *f, unsigned char (**x)[3], int w, int h);
void iio_save_image_uint8_matrix(char *f, unsigned char **x, int w, int h);


#define I_CAN_HAS_LIBPNG
#define I_CAN_HAS_LIBJPEG
#define I_CAN_HAS_LIBTIFF
//#define I_CAN_HAS_LIBEXR

#endif//_IIO_H
