/*
* arduino-serial-bones
*-----------------------
* A simple program to read serial input from the Volume Knob
*
* Largely based on todbot's arduino-serial program
*
* Compile with something like:
*  gcc -o arduino-serial arduino-serial-lib.c arduino-serial.c
*  
* 
*
*/

#include <stdio.h>    // Standard input/output definitions
#include <stdlib.h>
#include <string.h>   // String function definitions
#include <unistd.h>   // for usleep()
#include <getopt.h>

#include "arduino-serial-lib.h"

int main(int argc, char *argv[])
{
    const int buf_max = 256;

    int fd = -1;
    char serialport[buf_max];
    int baudrate = 115200;  // default
    char quiet=0;
    char eolchar = '\n';
    int timeout = 5000;
    char buf[buf_max];
    int rc,n;

    if (argc==1) {
        usage();
    }
    
    while(1) {
            if( fd == -1 ) error("serial port not opened");
            memset(buf,0,buf_max);  //
            serialport_read_until(fd, buf, eolchar, buf_max, timeout);
            if( !quiet ) printf("read string:");
            printf("%s\n", buf);
            ;
            
    }
}