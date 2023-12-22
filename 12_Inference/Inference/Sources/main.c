#include "nn.h"
#include "utils.h"

int main(){
    const int ninputs = 256;
    const int noutputs = 10;
    const Data inference = build("new_data.data", ninputs, noutputs);
    const NeuralNetwork_Type nn = NN_load("model.nn");
    const float * const input = inference.inputs[1];
    const float * const prediction = NN_predict(nn, *input);

    NN_print(prediction, inference.noutputs);
    NN_free(nn);
    dFree(inference);
    return 0;
}