#include <stdio.h>
#include <stdlib.h>
#include <simple_neural_networks.h>

double temperature[] = {12, 23, 50, -10, 16};
double weight = -2;

int main(){
    for (int i = 0; i < 5; i++) {
        printf("The %i predicted value is %f:\r\n", i, single_in_single_out(temperature[i], weight));
    }
    return 0;
}