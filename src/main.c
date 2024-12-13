#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "utils.h"

int main(){

    int len;
    char *buf;

    FILE* fp;
    fp = fopen("test.txt", "a+");

    if(fp == NULL) {

        printf("The file is not opened");
        exit(0);

    }

    len = getFileLen(fp);
    buf = readFileBytes(len, fp);
    printHex(buf, len);

    return 0;

}


