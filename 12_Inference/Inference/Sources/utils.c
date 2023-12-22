#include "utils.h"

int nLines(FILE *const file){
    int ch = EOF;
    int line_counter = 0;
    int pc = '\n';

    while((ch = getc(file)) != EOF){
        if(ch == '\n'){
            line_counter++;
        }
        pc = ch;
    }
    if(pc != '\n'){
        line_counter++;
    }
    rewind(file);
    return line_counter;
}

char * readln(FILE *const file){
    int ch = EOF;
    int reads = 0;
    int size = 128;
    char * line = (char *)malloc((size)*sizeof(char)); // Memory allocation

    while((ch = getc(file)) != '\n' && ch != EOF){
        line[reads++] = ch;
        if(reads+1 == size){
            line = (char *)realloc((line), (size *=2)*sizeof(char)); // Memory reallocation to the new size
        }
    }
    line[reads] = '\0';
    return line;
}

float ** new2dArr(const int rows, const int cols){
    float **row = (float **)malloc((rows)*sizeof(float *));
    
    for(int r = 0; r < rows; r++){
        row[r] = (float *)malloc((cols)*sizeof(float));
    }
    return row;
}

Data nData(const int ninputs, const int noutputs, const int rows){
    const Data data = {
        new2dArr(rows, ninputs),
        new2dArr(rows, noutputs),
        ninputs,
        noutputs,
        rows
    };
    return data;
}

void parse(const Data data, char * line, const int row){
    const int cols = data.ninputs + data.noutputs;
    for(int col = 0; col < cols; col++){
                    // ASCII to float - Tokenizing a String - String, Separator
        const float token = atof(strtok(col == 0 ? line : NULL, " "));
        if(col < data.ninputs){
            data.inputs[row][col] = token;
        }else{
            data.target[row][col - data.ninputs] = token;
        }
    }
}

void dFree(const Data d){
    for(int row = 0; row < d.rows; row++){
        free(d.inputs[row]);
        free(d.target[row]);
    }
    free(d.inputs);
    free(d.target);
}

void shuffle(const Data d){
    for(int i = 0; i < d.rows; i++){
        const int j = rand() %d.rows;
        float * ot = d.target[i];
        float * it = d.inputs[i];

        d.target[i] = d.target[j];
        d.target[j] = ot;
        d.inputs[i] = d.inputs[j];
        d.inputs[j] = it;
    }
}

Data build(const char * path, const int ninputs, const int noutputs){
    FILE * file = fopen(path, "r");
    if(file == NULL){
        printf("File not found! %s\n", path);
        printf("Dataset might not exist\n");
        exit(1);
    }
    const int rows = nLines(file);
    Data data = nData(ninputs, noutputs, rows);
    for(int row = 0; row < rows; row++){
        char * line = readln(file);
        parse(data, line, row);
        free(line);
    }
    fclose(file);
    return data;
}