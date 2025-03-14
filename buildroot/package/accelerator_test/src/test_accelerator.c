//user application
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

#include "accelerator_test.h"

#define DEVICE "/dev/accelerator"

#define max_in_wordspackage_per_channel 4
#define max_in_channels 16
#define kernel_size 8

int main() {
    int i,fd_device,fd_input;
    
    int dev = open(DEVICE, O_RDWR);
    if(dev == -1) {
    	printf("Opening the device file was not possible!\n");
	return -1;
    }
    FILE* fd_results; //file descriptor to print output values
    //FILE* fd_golden_results; //file descriptor to get golden model results
    int64_t golden_out_data;
    struct inputstruct data;

    fd_results = fopen("results_accelerator.txt", "w");
    if (fd_results == NULL) {
	printf("Error opening results file.\n");
	exit(-1);
    }
    /*fd_golden_results = fopen("results_golden_model.txt", "r");
    if (fd_golden_results == NULL) {
	printf("Error opening golden results file.\n");
	exit(-1);
    }*/
    
    data.n_input_channels = 4;
    data.sequence_length = 2;
    
    for (int k=0; k<kernel_size; k++) {
    	data.coefficients[k] = (k+1)*(0x3456789382723583);
    	printf("Filter set nr %d uploaded: %llx \n", k+1, data.coefficients[k]);
    }
    
    for (int i=0; i<data.n_input_channels; i++) {
        for (int j=0; j<data.sequence_length*8; j++) {
            data.data_in_struct[i][j] = (0x6937593827484747*j)+(0x44AABBCC85791FFF*(i+1));
            printf("Input word %d of channel %d: %llx \n", j+1, i+1, data.data_in_struct[i][j]);
        }
    }
    
    ioctl(dev, ACCELERATOR_FUNC, &data);
    
    for (int i=0; i<kernel_size; i++) {
        for (int j=0; j<(data.sequence_length*8)-8+1; j++) {
            //printf("Data of output channel %d word %d: %llx \n", i+1, j+1, data.data_out_struct[i][j]);
            //write in a txt file the output data
            fprintf(fd_results, "%llx\n", data.data_out_struct[i][j]);
            //read golden model outputs
            //fscanf(fd_golden_results, "%lx\n", &golden_out_data);
            //if(golden_out_data != data.data_out_struct[i][j])
                //printf("Output data [%d][%d] = %lx differs from golden output = %lx\n", i+1, j+1, data.data_out_struct[i][j], golden_out_data);
        }
    }

    fclose(fd_results);
    //fclose(fd_golden_results);
	
    return 0;
}
