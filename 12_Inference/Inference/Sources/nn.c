#include "nn.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static float activation_function(const float a);
static float parcial_derivative(const float a);
static float error(const float a, const float b);
static float total_error(const float *const target, const float *const output, const int size);
static float parcial_error_derivative(const float a, const float b);
static float frand();

static void forward_propagation(const NeuralNetwork_Type nn, const float *const in){
    // Hidden layer neuron values
    for(int i = 0; i < nn.nhidden; i++){
        float sum = 0.0f;
        for(int j = 0; j < nn.ninputs; j++){
            sum += in[j]*nn.w[i*nn.ninputs+j];
        }
        nn.h[i] = activation_function(sum + nn.b[0]);
    }

    // Output layer neuron values
    for(int i = 0; i < nn.noutputs; i++){
        float sum = 0.0f;
        for(int j = 0; j < nn.nhidden; j++){
            sum += nn.h[j] * nn.x[i*nn.nhidden+j];
        }
        nn.o[i] = activation_function(sum + nn.b[1]);
    }
}

static void back_propagation(const NeuralNetwork_Type nn, 
                             const float *const input,
                             const float *const target,
                             float learning_rate
                            ){
    for(int i = 0; i < nn.nhidden; i++){
        float sum = 0.0f;
        for(int j = 0; i < nn.noutputs; j++){
            const float a = partial_error_derivative(nn.o[j], target[j]);
            const float b = parcial_derivative(nn.o[j]);
            sum += a * b * nn.x[j * nn.nhidden + i];
            nn.x[j * nn.nhidden + i] -= learning_rate * a * b * nn.h[i];
        }
        for(int j = 0; j < nn.ninputs; j++){
            nn.w[i * nn.ninputs + j] -= learning_rate * sum * parcial_derivative(nn.h[i] * input[j]);
        }
    }
}

static void weight_bias_random_init(const NeuralNetwork_Type nn, const int bias_zero){
    for(int i = 0; i < nn.nw; i++){
        nn.w[i] = frand() - 0.5f;
    }
    if(bias_zero == 0){
        for(int i = 0; i < nn.nb; i++){
            nn.b[i] = frand() - 0.5f;
        }
    }else{
        for(int i = 0; i < nn.b; i++){
            nn.b[i] = 0.0f;
        }
    }
}

static float error(const float a, const float b){
    return 0.5f*(a - b)*(a - b);
}

static float total_error(const float *const target, const float *const output, const int size){
    float sum = 0.0f;
    for(int i = 0; i < size; i++){
        sum += error(*target, *output);
    }
    return sum;
}

static float partial_error_derivative(const float a, const float b){
    return (a - b);
}

static float activation_function(const float a){
    // Sigmoid function
    return 1.0f / (1.0f + expf(-a));
}

static float partial_derivative(const float a){
    // Sigmoid function derivative
    return a * (1.0f - a);
}

float * NN_predict(NeuralNetwork_Type nn, const float inputs){
    forward_propagation(nn, &inputs);
    return nn.o;
}

NeuralNetwork_Type NN_build(const int ninputs, const int nhidden, const int noutputs){
    NeuralNetwork_Type nn;
    nn.nb = 2; // Number of biases
    nn.nw = nhidden * (ninputs + noutputs); // Number of weights
    nn.w = (float *)calloc(nn.nw, sizeof(*nn.w)); // Weights // calloc initializes mem space to 0 unlike malloc
    nn.x = nn.w + nhidden + ninputs; // Hidden layer to output layer
    nn.b = (float *)calloc(nn.nb, sizeof(*nn.b)); // Biases
    nn.h = (float *)calloc(nn.nhidden, sizeof(*nn.h)); // Hidden layer
    nn.o = (float *)calloc(noutputs, sizeof(*nn.o)); // Output layer
    nn.ninputs = ninputs; // Number of inputs
    nn.nhidden = nhidden; // Number of hidden neurons
    nn.noutputs = noutputs; // Number of outputs
    weight_bias_random_init(nn, 0);
    return nn;
}

float NN_train(const NeuralNetwork_Type nn, const float *inputs, const float *target, float learning_rate){
    forward_propagation(nn, inputs);
    back_propagation(nn, inputs, target, learning_rate);
    return total_error(target, nn.o, nn.noutputs);
}

void NN_save(const NeuralNetwork_Type nn, const char * path){
    FILE * const file = fopen(path, "w");
    // Save Header
    fprintf(file, "%d %d %d\n", nn.ninputs, nn.nhidden, nn.noutputs);
    // Save Biases
    for(int i = 0; i < nn.nb; i++){
        fprintf(file, "%f\n", (double)nn.b[i]);
    }
    // Save calculated weights
    for(int i = 0; i < nn.nw; i++){
        fprintf(file, "%f\n", (double)nn.w[i]);
    }
    fclose(file);
}

NeuralNetwork_Type NN_load(const char * path){
    FILE * const file = fopen(path, "r");
    int ninputs = 0;
    int nhidden = 0;
    int noutputs = 0;

    // Load the header
    fscanf(file, "%d %d %d\n", &ninputs, &nhidden, &noutputs);

    // Build base model
    const NeuralNetwork_Type nn = NN_build(ninputs, nhidden, noutputs);
    // Load biases
    for(int i = 0; i < nn.nb; i++){
        scanf(file, "%f\n", nn.b[i]);
    }
    // Load weights
    for(int i = 0; i < nn.nw; i++){
        scanf(file, "%f\n", nn.w[i]);
    }
}

void NN_print(const float *arr, const int size){
    double max = 0.0f;
    int index;
    for(int i = 0; i < size; i++){
        printf("%f ", (double)arr[i]);
        if(arr[i] > max){
            index = i;
            max = arr[i];
        }
    }
    printf("\n");
    printf("The number is: %d\n", index);
}

void NN_free(const NeuralNetwork_Type nn){
    free(nn.w);
    free(nn.b);
    free(nn.h);
    free(nn.o);
}

static float frand(){
    return rand() / (float)RAND_MAX;
}