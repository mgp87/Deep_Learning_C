#ifndef _HIDDEN_LAYER_NN_H
#define _HIDDEN_LAYER_NN_H
#define HIDDEN_LEN 3 // number of nodes
double hidden_pred_vector[HIDDEN_LEN];
void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector);
#endif