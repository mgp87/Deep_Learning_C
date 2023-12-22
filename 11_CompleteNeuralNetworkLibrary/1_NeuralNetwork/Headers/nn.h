#ifndef NN_H
#define NN_H

typedef struct{
    float *w;       // Weights
    float *x;       // Hidden layer to output layer
    float *b;       // Biases
    float *h;       // Hidden layer
    float *o;       // Output layer
    int nb;         // Number of biases
    int nw;         // Number of weights
    int ninputs;    // Number of inputs
    int nhidden;    // Number of hidden neurons
    int noutputs;   // Number of outputs
} NeuralNetwork_Type;

float * NN_predict(NeuralNetwork_Type nn, const float inputs);
NeuralNetwork_Type NN_build(const int ninputs, const int nhidden, const int noutputs);
float NN_train(const NeuralNetwork_Type nn, const float *inputs, const float *target, float learning_rate);
void NN_save(const NeuralNetwork_Type nn, const char * path);
NeuralNetwork_Type NN_load(const char * path);
void NN_print(const float *arr, const int size);
void NN_free(const NeuralNetwork_Type nn);

#endif