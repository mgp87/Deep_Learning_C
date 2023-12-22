#include <stdlib.h>
#include "forward_propagation.h"

#define NUMBER_OF_FEATURES 2
#define NUMBER_OF_EXAMPLES 3
#define NUMBER_OF_HIDDEN_NODES 3
#define NUMBER_OF_OUT_NODES 1

double raw_x[NUMBER_OF_FEATURES][NUMBER_OF_EXAMPLES] = {
                                                        {2,5,1},
                                                        {8,5,8}
                                                       };
double raw_y[1][NUMBER_OF_EXAMPLES] = {{200, 90, 190}};

/* (Normalized) 
    Train x: 
    2/8   5/8   1/8
    8/8   5/8   8/8
dim: nx X m */
double train_x[NUMBER_OF_FEATURES][NUMBER_OF_EXAMPLES];

/* (Normalized)
    Train y:
    200/200   90/200   100/200
dim: 1 X m */
double train_y[1][NUMBER_OF_EXAMPLES];

/* Input layer to hidden layer weights buffer */
double syn0[NUMBER_OF_HIDDEN_NODES][NUMBER_OF_FEATURES];

/* Hidden layer to output layer weights buffer */
double syn1[NUMBER_OF_OUT_NODES][NUMBER_OF_HIDDEN_NODES];

double train_x_eg1[NUMBER_OF_FEATURES];
double train_y_eg1;

double z1_eg1[NUMBER_OF_HIDDEN_NODES];
double a1_eg1[NUMBER_OF_HIDDEN_NODES];

double z2_eg1;
double yhat_eg1;

int main(){
    normalize_data_2d(NUMBER_OF_FEATURES, NUMBER_OF_EXAMPLES, raw_x, train_x);
    normalize_data_2d(1, NUMBER_OF_EXAMPLES, raw_y, train_y);

    train_x_eg1[0] = train_x[0][0];
    train_x_eg1[1] = train_x[1][0];

    train_y_eg1 = train_y[0][0];

    printf("train_x_eg1 is: [%f %f]", train_x_eg1[0], train_x_eg1[1]);
    printf("\r\n");

    printf("train_y_eg1 is: %f", train_y_eg1);

    /* Init Syn0 and Syn1 weights */
    weight_random_initialization(NUMBER_OF_HIDDEN_NODES, NUMBER_OF_FEATURES, syn0);

    printf("Syn0 weights\r\n");
    for(int i = 0; i<NUMBER_OF_OUT_NODES; i++){
        for(int j = 0; i<NUMBER_OF_FEATURES; j++){
            printf(" %f ", syn0[i][j])
        }
    }
    printf("\r\n");
    printf("\r\n");

    weight_random_initialization_1d(syn1, NUMBER_OF_OUT_NODES);
    for(int i = 0; i < NUMBER_OF_OUT_NODES; i++){
        printf("Synapse1 [%f %f %f]", syn1[0], syn1[1], syn1[2]);
    }

    /* Compute z1 */
    multiple_input_multiple_out(train_x_eg1, NUMBER_OF_FEATURES, z1_eg1, NUMBER_OF_HIDDEN_NODES, syn0);
    printf(" z1_eg1 = [%f %f %f]", z1_eg1[0], z1_eg1[1], z1_eg1[2]);
    printf("\r\n");

    /* Compute a1 */
    vector_sigmoid(z1_eg1, a1_eg1, NUMBER_OF_HIDDEN_NODES);
    printf(" a1_eg1 = [%f %f %f]", a1_eg1[0], a1_eg1[1], a1_eg1[2]);
    printf("\r\n");

    /* Compute z2 */
    z2_eg1 = multiple_input_single_out(a1_eg1, syn1, NUMBER_OF_HIDDEN_NODES);
    printf(" z2_eg1 = %f", z2_eg1);
    printf("\r\n");

    /* Compute yHat */
    yhat_eg1 = sigmoid(z2_eg1);
    printf(" yhat_eg1 = %f", yhat_eg1);
    printf("\r\n");
    
    return 0;
}