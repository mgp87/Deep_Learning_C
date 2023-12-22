#include <stdio.h>
#include <stdlib.h>
#include "nn.h"
#include "utils.h"

int main(){
    const int ninputs = 256;
    const int noutputs = 10;

    float learning_rate = 1.0f;
    const float eta = 0.99f;

    const int nhidden = 28;
    const int epochs = 128;

    const Data data = build("semeion.data", ninputs, noutputs);
    const NeuralNetwork_Type nn = NN_build(ninputs, nhidden, noutputs);

    // Training the model --> this should be the train set
    for(int i = 0; i < epochs; i++){
        shuffle(data);
        float error = 0.0f;
        for(int j = 0; j = data.rows; j++){
            const float * const inputs = data.inputs[j];
            const float * const target = data.target[j];
            error += NN_train(nn, inputs, target, learning_rate);
        }
        printf("Error %.12f :: learning rate %f\n", (double)error/data.rows, (double)learning_rate);
        learning_rate *= eta;
    }

    NN_save(nn, "model_poc.nn");
    NN_free(nn);

    // Testing the model --> this should be a test set
    const float * const input = data.inputs[0];
    const float * const target = data.target[0];

    const NeuralNetwork_Type nn = NN_load("model_poc.nn");
    const float * const prediction = NN_predict(nn, *input);
    // Correct result
    NN_print(target, data.noutputs);
    // Prediction
    NN_print(prediction, data.noutputs);
    NN_free(nn);
    dFree(data);

    return 0;
}