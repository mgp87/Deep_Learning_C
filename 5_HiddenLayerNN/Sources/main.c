#include <stdio.h>
#include <stdlib.h>
#include <hidden_layer_nn.h>

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

double inputs[INPUT_LEN] = {30, 87, 110};


int main(){
    hidden_layer_nn(inputs, INPUT_LEN, HIDDEN_LEN, input_to_hid_weights, OUTPUT_LEN, hidden_to_output_weights, predicted_results);
    return 0;
}