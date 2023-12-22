#include <stdio.h>
#include <stdlib.h>
#include <multiple_input_multiple_output.h>

#define INPUT_LEN 3
#define OUTPUT_LEN 3

#define SAD_INDEX 0
#define SICK_INDEX 1
#define ACTIVE_INDEX 2

double predicted_results[3];

double weight_matrix[OUTPUT_LEN][INPUT_LEN] = {
                                                {-2, 9.5, 2.01},
                                                {-0.8, 7.2, 6.3},
                                                {-0.5, 0.45, 0.9}
                                              };

double inputs[INPUT_LEN] = {30, 87, 110};


int main(){
    multiple_input_multiple_out(inputs, INPUT_LEN, predicted_results, OUTPUT_LEN, weight_matrix);
    printf("Sad prediction %f:\r\n", predicted_results[SAD_INDEX]);
    printf("Sick prediction %f:\r\n", predicted_results[SICK_INDEX]);
    printf("Active prediction %f:\r\n", predicted_results[ACTIVE_INDEX]);
    return 0;
}