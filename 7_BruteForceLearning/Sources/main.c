#include <stdio.h>
#include <stdlib.h>
#include "brute_force_learning.h"

double weight = 0.5;
double input = 0.5;
double expected_value = 0.8;
double step_amount = 0.001;

int main(){
    brute_force_learning(input, weight, expected_value, step_amount, 800);
    return 0;
}