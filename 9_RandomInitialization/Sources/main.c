#include <stdlib.h>
#include "random_initialization.h"

#define NUMBER_OF_FEATURES 2
#define NUMBER_OF_EXAMPLES 3
#define NUMBER_OF_HIDDEN_NODES 3
#define NUMBER_OF_OUT_NODES 1

/* HOURS OF WORKOUT */
double x1[NUMBER_OF_EXAMPLES] = {2, 5, 1};
double _x1[NUMBER_OF_EXAMPLES];

/* HOURS OF REST */
double x2[NUMBER_OF_EXAMPLES] = {8, 5, 8};
double _x2[NUMBER_OF_EXAMPLES];

/* MUSCLE GAIN */
double y[NUMBER_OF_EXAMPLES] = {200, 90, 190};
double _y[NUMBER_OF_EXAMPLES];

/* Input layer to hidden layer weights buffer */
double syn0[NUMBER_OF_HIDDEN_NODES][NUMBER_OF_FEATURES];

/* Hidden layer to output layer weights buffer */
double syn1[NUMBER_OF_OUT_NODES][NUMBER_OF_HIDDEN_NODES];

int main(){
    weight_random_initialization(NUMBER_OF_HIDDEN_NODES, NUMBER_OF_FEATURES, syn0);
    weight_random_initialization(NUMBER_OF_HIDDEN_NODES, NUMBER_OF_FEATURES, syn1);
    printf("Syn0 weights\r\n");
    for(int i = 0; i<NUMBER_OF_OUT_NODES; i++){
        for(int j = 0; i<NUMBER_OF_FEATURES; j++){
            printf(" %f ", syn0[i][j])
        }
    }
    printf("\r\n");
    printf("Syn1 weights\r\n");
    for(int i = 0; i<NUMBER_OF_OUT_NODES; i++){
        for(int j = 0; i<NUMBER_OF_FEATURES; j++){
            printf(" %f ", syn1[i][j])
        }
    }
    printf("\r\n");
    return 0;
}