#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <ctype.h>

int getFileLen(FILE*);

char * readFileBytes(int, FILE*);

void printCounter(int, unsigned long *);

void printHex(char *, int);

#endif 
