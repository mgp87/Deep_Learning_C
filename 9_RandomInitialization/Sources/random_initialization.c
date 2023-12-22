#include "random_initialization.h"
#include <math.h>

void matrix_vector_multiply(double * input_vector, int INPUT_LEN, double * output_vector, 
                            int OUTPUT_LEN, double weight_matrix[OUTPUT_LEN][INPUT_LEN]){
    for(int k = 0; k<OUTPUT_LEN; k++){
        for(int i=0; i<INPUT_LEN; i++){
            output_vector[k] += input_vector[i] * weight_matrix[k][i];
        }
    }
}

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector){
    matrix_vector_multiply(input_vector, INPUT_LEN, hidden_pred_vector, OUTPUT_LEN, in_to_hid_weights);
    matrix_vector_multiply(hidden_pred_vector, HIDDEN_LEN, output_vector, OUTPUT_LEN, hid_to_out_weights);
}

double find_error(double input, double weight, double expected_value){
    return powf(((input * weight) - expected_value),2);
}

double find_error_simple(double yhat, double y){
    return powf((yhat - y), 2);
}

void brute_force_learning(double input, double weight, double expected_value, double step_amount, int epochs){
    double prediction, error;
    double up_prediction, up_error, down_prediction, down_error;
    for(int i=0; i<epochs; i++){
        prediction = input * weight;
        error = powf((prediction - expected_value), 2);
        printf("Error: %f Prediction: %f \r\n", error, prediction);

        // COMPARING THE ERROR INCREASING THE WEIGHT AGAINST THE ERROR DECREASING THE WEIGHT, WE FIND THE 
        // DIRECTION TO FOLLOW
        up_prediction = input * (weight + step_amount);
        up_error = powf((expected_value - up_prediction), 2);

        down_prediction = input * (weight - step_amount);
        down_error = powf((expected_value - down_prediction), 2);

        if(down_error < up_error){
            weight = weight - step_amount;
        }
        if(down_error > up_error){
            weight = weight + step_amount;
        }
    }
}

void normalize_data(double *input_vector, double *output_vector, int LEN){
    int i;
    // FIND MAX
    double max = input_vector[0];

    for(i=1; i<LEN; i++){
        if(input_vector[i] > max){
            max = input_vector[i];
        }
    }

    // NORMALIZATION
    for(i=0; i<LEN; i++){
        output_vector[i] = input_vector[i] / max;
    }
}

void weight_random_initialization(int HIDDEN_LEN, int INPUT_LEN, double weight_matrix[HIDDEN_LEN][INPUT_LEN]){
    double d_rand;
    /* Seed random number generator */
    srand(2);
    for(int i = 0; i<HIDDEN_LEN; i++){
        for(int j = 0; j<INPUT_LEN; j++){
            /* Generate random numbers between 0 and 1 */
            d_rand = (rand()%10);
            d_rand /= 10;
            weight_matrix[i][j] = d_rand;
        }
    }
}