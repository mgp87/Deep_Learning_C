#include "multiple_input_multiple_output.h"

double weighted_sum(double * input, double * weight, int LEN){
    double output;
    for(int i = 0; i < LEN; i++){
        output += input[i] * weight[i];
    }
    return output;
}

double multiple_input_single_out(double * input, double * weight, int LEN){
    double predicted_value = weighted_sum(input, weight, LEN);
    return predicted_value;
}

void matrix_vector_multiply(double * input_vector, int INPUT_LEN, double * output_vector, 
                            int OUTPUT_LEN, double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    for(int k = 0; k<OUTPUT_LEN; k++){
        for(int i=0; i<INPUT_LEN; i++){
            output_vector[k] += input_vector[i] * weight_matrix[k][i];
        }
    }
}

void multiple_input_multiple_out(double * input_vector, int INPUT_LEN, double * output_vector, 
                            int OUTPUT_LEN, double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    matrix_vector_multiply(input_vector, INPUT_LEN, output_vector, OUTPUT_LEN, weight_matrix);
}