#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float ** inputs;    // 2D array for inputs
    float ** target;    // 2D array for targets
    int ninputs;        // Number of inputs
    int noutputs;       // Number of outputs
    int rows;           // Number of rows
} Data;

char * readln(FILE *const file);
float ** new2dArr(const int rows, const int cols);
Data nData(const int ninputs, const int noutputs, const int rows);
void parse(const Data data, char * line, const int row);
void dFree(const Data d);
void shuffle(const Data d);
Data build(const char * path, const int ninputs, const int noutputs);
int nLines(FILE *const file);

#endif