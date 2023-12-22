#ifndef _FORWARD_PROPAGATION_H
#define _FORWARD_PROPAGATION_H
#include <stdio.h>
#include <stdlib.h>

#define HIDDEN_LEN 3 // number of nodes
double hidden_pred_vector[HIDDEN_LEN];

double single_in_single_out(double input, double weight);
void single_in_multiple_out_nn(double input_scalar, double * weight_vector, double * output_vector, int LEN);
double multiple_input_single_out(double * input, double * weight, int LEN);
void multiple_input_multiple_out(double * input_vector, int INPUT_LEN, double * output_vector, 
                            int OUTPUT_LEN, double weight_matrix[OUTPUT_LEN][INPUT_LEN]);
void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector);
double find_error(double input, double weight, double expected_value);
double find_error_simple(double yhat, double y);
void brute_force_learning(double input, double weight, double expected_value, double step_amount, int epochs);
void normalize_data(double *input_vector, double *output_vector, int LEN);
void weight_random_initialization(int HIDDEN_LEN, int INPUT_LEN, double weight_matrix[HIDDEN_LEN][INPUT_LEN]);
void normalize_data_2d(int ROW, int COL, double input_matrix[ROW][COL], double output_matrix[ROW][COL]);
void weight_random_initialization_1d(double * output_vector, int LEN);
double sigmoid(double x);
void vector_sigmoid(double * input_vector, double * output_vector, int LEN);

#endif