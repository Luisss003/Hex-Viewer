#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int getFileLen(FILE *fp) {

    int len;

    if (fp == NULL) {
        perror("Error opening file");
        exit(0);
    }   

    fseek(fp, 0, SEEK_SET);
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);
    return len;

}

char *readFileBytes(int fileLen, FILE *fp) {

    char *buf = malloc(sizeof(char) * fileLen + 1);
    fread(buf, fileLen, 1, fp);
    buf[fileLen+1] = '\0';
    return buf;

}


void printHex(char *numChars, int len) {

    int i, j;
    unsigned long start = 0x0000000000000000;

    int cols = 10;
    for(i = 0; i < len; i++) {
        
        if(i % cols == 0) {
            printf("0x%016lx: ", start);
            start += cols;
        }
        
        printf("%02X", numChars[i]);
    
        if((i + 1) % 2 == 0) {
            printf(" ");
        }

        if ((i + 1) % cols == 0 || i == len - 1) {
            if (i == len - 1 && (i + 1) % cols != 0) {
                int padding = cols - ((i + 1) % cols);
                for (j = 0; j < padding; j++) {
                    printf("   "); 
                }
                if (padding > 4) printf(" ");
            }

            printf(" ");
            for (j = i - ((i % cols)) ; j <= i; j++) {
                if (isprint((unsigned char)numChars[j])) {
                    printf("%c", numChars[j]); 
                } 
                else {
                    printf("."); 
                }
            }
            printf("\n");

        }
    }
}




