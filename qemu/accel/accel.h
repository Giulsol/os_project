#ifndef ACCEL_H
#define ACCEL_H

#include <stdio.h>
#include <stdint.h>

#define max_in_channels 16
#define kernel_size 8
#define max_in_wordspackage_per_channel 4  
#define max_bytes_per_channel_in 32
#define output_word_bytes 8

void convolution_8_per_n_ch_in(uint64_t data[max_in_channels][max_in_wordspackage_per_channel], uint64_t coefficients, uint64_t n_input_channels, uint64_t seq_length, uint64_t *sum);

#endif // ACCEL_H

