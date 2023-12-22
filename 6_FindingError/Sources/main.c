#include <stdio.h>
#include <stdlib.h>
#include "finding_error.h"

#define INPUT_LEN 3
#define OUTPUT_LEN 3

#define SAD_INDEX 0
#define SICK_INDEX 1
#define ACTIVE_INDEX 2

double predicted_results[3];

double input_to_hid_weights[HIDDEN_LEN][INPUT_LEN] = {
                                                        {-2, 9.5, 2.01}, // hid[0]
                                                        {-0.8, 7.2, 6.3}, // hid[1]
                                                        {-0.5, 0.45, 0.9} // hid[2]
                                                      };

double hidden_to_output_weights[OUTPUT_LEN][HIDDEN_LEN] = {
                                                            {-1.0, 1.15, 0.11}, // sad
                                                            {-1.18, 0.15, -0.01}, // sick
                                                            {0.25, -0.25, -0.1} // active
                                                          };

double expected_values[OUTPUT_LEN] = {600, 10, -90};

double inputs[INPUT_LEN] = {30, 87, 110};


int main(){
    hidden_layer_nn(inputs, INPUT_LEN, HIDDEN_LEN, input_to_hid_weights, OUTPUT_LEN, hidden_to_output_weights, predicted_results);
    printf("Sad prediction %f:\r\n", predicted_results[SAD_INDEX]);
    printf("Sad error %f: \r\n", find_error_simple(predicted_results[SAD_INDEX], expected_values[SAD_INDEX]));
    printf("Sick prediction %f:\r\n", predicted_results[SICK_INDEX]);
    printf("Sick error %f: \r\n", find_error_simple(predicted_results[SICK_INDEX], expected_values[SICK_INDEX]));
    printf("Active prediction %f:\r\n", predicted_results[ACTIVE_INDEX]);
    printf("Active error %f: \r\n", find_error_simple(predicted_results[ACTIVE_INDEX], expected_values[ACTIVE_INDEX]));
    return 0;
}