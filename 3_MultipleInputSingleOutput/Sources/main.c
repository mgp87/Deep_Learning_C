#include <stdio.h>
#include <stdlib.h>
#include <multiple_input_single_output.h>

#define NUMBER_OF_INPUTS 3

double temperature[] = {12, 23, 50, -10, 16};
double humidity[] =    {60, 67, 50, 65, 63};
double air_quality[] = {60, 47, 167, 187, 94};

double weight[] =      {-2, 2, 1};

int main(){
    double training_eg1[] = {temperature[0], humidity[0], air_quality[0]};
    printf("Prediction from the first example is %f:\r\n", multiple_input_single_out(training_eg1, weight, NUMBER_OF_INPUTS));
    return 0;
}