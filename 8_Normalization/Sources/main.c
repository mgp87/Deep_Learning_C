#include <stdlib.h>
#include "normalization.h"

#define NUMBER_OF_FEATURES 2
#define NUMBER_OF_EXAMPLES 3

/* HOURS OF WORKOUT */
double x1[NUMBER_OF_EXAMPLES] = {2, 5, 1};
double _x1[NUMBER_OF_EXAMPLES];

/* HOURS OF REST */
double x2[NUMBER_OF_EXAMPLES] = {8, 5, 8};
double _x2[NUMBER_OF_EXAMPLES];

/* MUSCLE GAIN */
double y[NUMBER_OF_EXAMPLES] = {200, 90, 190};
double _y[NUMBER_OF_EXAMPLES];

int main(){
    normalize_data(x1, _x1, NUMBER_OF_EXAMPLES);    
    normalize_data(x2, _x2, NUMBER_OF_EXAMPLES);    
    normalize_data(y, _y, NUMBER_OF_EXAMPLES);
    printf("Raw data:\r\n");

    for(int i=0; i<NUMBER_OF_EXAMPLES; i++){
        printf("%f", x1[i]);
        printf("%f", x2[i]);
        printf("%f", y[i]);
    }
    printf("\r\n");

    printf("Normalized data:\r\n");
    for(int i=0; i<NUMBER_OF_EXAMPLES; i++){
        printf("%f", _x1[i]);
        printf("%f", _x2[i]);
        printf("%f", _y[i]);
    }
    printf("\r\n");

    return 0;
}