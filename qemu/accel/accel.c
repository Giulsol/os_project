// Copyright (c) 2019-2022 Phantom1003

#include<stdint.h>
#include "accel/accel.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define in_words_per_transaction 8

//convolution 8*n_ch_in calculus
void convolution_8_per_n_ch_in(uint64_t data[max_in_channels][max_in_wordspackage_per_channel], uint64_t coefficients, uint64_t n_input_channels, uint64_t seq_length, uint64_t *sum) {
    //64 bits of data = 8 Bytes of data = 8 words
    //max_in_wordspackage_per_channel of 64 bits of data = at maximum 4 * 64
    //all multiplied for max_in_channels => at maximum: 16 * 4 * 64 bits of data
    //64 bits of coefficients = 8 Bytes = 8 coefficients (that form a filter set)
    uint64_t data_in[in_words_per_transaction][max_in_channels][max_in_wordspackage_per_channel];
    uint64_t coeff[kernel_size];

    
    //decode of the input coefficients
    //first (LSBs) 4 bits = 1B are the first coefficient 
    for (int i=0; i<kernel_size; i++) {
        coeff[i] = ((coefficients << (64-4*(i+1))) >> 60);
    }

    uint64_t partial_sum;
    int p = 0, a = 0, b, c;

    //decode of the input words
    //first (LSBs) 4 bits = 1B are the first word
    for (int j=0; j<seq_length; j++) {
        for (int i=0; i<n_input_channels; i++) {
            for (int k=0; k<in_words_per_transaction; k++) {
                data_in[k][i][j] = ((data[i][j] << (64-4*(k+1))) >> 60);
            }
        }
    }

    for (int q=0; q<(seq_length-1)*in_words_per_transaction; q++) {
        if (p != 0 && (q % 8) == 0) {
            p++;
        }
        partial_sum = 0;
        for (int i=0; i<n_input_channels; i++) {
            c = 0;
            b = 0;
            for (int k=0; k<in_words_per_transaction; k++) {
                if (k==in_words_per_transaction-a) {
                    c = k + a;
                    b++;
                }
                partial_sum += data_in[k+a-c][i][p+b]*coeff[k]; //sum of the 5 elements
            }
        }
        sum[q] = partial_sum;
        a++;
        if (a == 8) {
            a = 0;
        }
    }

    partial_sum = 0;
    for (int i=0; i<n_input_channels; i++) {
        for (int k=0; k<in_words_per_transaction; k++) {
            partial_sum += data_in[k][i][seq_length-1]*coeff[k];
        }
    }
    sum[(seq_length-1)*in_words_per_transaction] = partial_sum;
}

