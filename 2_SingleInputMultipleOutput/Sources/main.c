#include <stdio.h>
#include <stdlib.h>
#include <single_input_multiple_output.h>

#define SAD 0.9
#define TEMPERATURE_PREDICTION_INDEX 0
#define HUMIDITY_PREDICTION_INDEX 1
#define QUALITY_PREDICTION_INDEX 2
#define VECTOR_LEN 3

double predicted_results[3];
double weights[3] = {-20, 95, 201};

int main(){
    single_in_multiple_out_nn(SAD, weights, predicted_results, VECTOR_LEN);
    printf("Predicted temperature is: %f \r\n", predicted_results[TEMPERATURE_PREDICTION_INDEX]);
    printf("Predicted humidity is: %f \r\n", predicted_results[HUMIDITY_PREDICTION_INDEX]);
    printf("Predicted air quality is: %f \r\n", predicted_results[QUALITY_PREDICTION_INDEX]);
    return 0;
}