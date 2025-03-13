//user application
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "accelerator_test.h"

#define DEVICE "/dev/accelerator"
#define INPUT "./input_data"

#define max_in_wordspackage_per_channel 4
#define max_in_channels 16
#define kernel_size 8

int main() {
    int i,fd_device,fd_input;
    char ch, write_buff[256], read_buf[256];
    
    int dev = open(DEVICE, O_RDWR);
    
    struct inputstruct data;
    
    data.n_input_channels = 4;
    data.sequence_length = 2;
    
    for (int k=0; k<kernel_size; k++) {
    	data.coefficients[k] = (k+1)*(0x3456789382723583);
    	printf("Filter set nr %d uploaded \n", k+1);
    }
    
    for (int i=0; i<data.n_input_channels; i++) {
        for (int j=0; j<data.sequence_length*8; j++) {
            data.data_in_struct[i][j] = (0x6937593827484747*j)+(0x44AABBCC85791FFF*(i+1));
            printf("Data of set %d channel %d: %lx \n", i+1, j+1, data.data_in_struct[i][j]);
        }
    }
    
    ioctl(dev, ACCELERATOR_FUNC, &data);
    
    for (int i=0; i<kernel_size; i++) {
        for (int j=0; j<(data.sequence_length*8)-8+1; j++) {
            printf("Data of output channel %d word %d: %lx \n", i+1, j+1, data.data_out_struct[i][j]);
        }
    }
	
	/*
    fd_device = open(DEVICE, O_RDWR); //Open for reading and writing
    fd_input = open(INPUT, O_RDONLY); //Open for reading
    if (fd_device == -1) {
        printf("file %s either does not exist or has been locked by another process\n", DEVICE);
        exit(-1);
    }
    if (fd_input == -1) {
        printf("file %s either does not exist or has been locked by another process\n", INPUT);
        exit(-1);
    }
    printf("w = write to device\n s = start accel\n  r = read from device\n Enter command: ");
    scanf("%c",&ch);

    switch (ch) {
        case 'w':
            printf("Copying data to the accelerator");
            //want to save in write_buf the data just read from the input file that will go to the accelerator
            ssize_t read_size = read(fd_input, write_buf, 256);
            if (read_size = -1) {
                printf("Was not able to read data from the file");
                exit(-1);
            }
            
            ssize_t write_size = write(fd_device, write_buf, sizeof(write_buf));
            if (write_size = -1) {
                printf("Was not able to write data to the file");
                exit(-1);
            }
            break;
        case 's':
            //start bit is written 
            printf("Start bit written\n");
            int start = 1;
            ssize_t start = write(fd_device, start, sizeof(int));
            if (start = -1) {
                printf("Was not able to write start bit to the file");
                exit(-1);
            }
            break;
        case 'r':
            //read output from accelerator
            printf("Reading output\n");
            ssize_t read_out = read(fd_device, read_buf, sizeof(read_buf));
            if (read_out = -1) {
                printf("Was not able to read data from the device");
                exit(-1);
            }
            break;
        default:
            printf("Command not recognized\n");
            break;
    }
    */
    return 0;
}
