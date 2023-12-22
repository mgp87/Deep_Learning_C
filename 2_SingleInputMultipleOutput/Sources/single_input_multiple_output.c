#include "single_input_multiple_output.h"

void elementwise_multiply(double input_scalar, double * weight_vector, double * output_vector, int LEN){
    for(int i=0; i<LEN; i++){
        output_vector[i] = input_scalar * weight_vector[i];
    }
}

void single_in_multiple_out_nn(double input_scalar, double * weight_vector, double * output_vector, int LEN){
    elementwise_multiply(input_scalar, weight_vector, output_vector, LEN);
}