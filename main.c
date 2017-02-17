/*This program is a demostration of MNIST recognition task implemented in C programming language*/
//No bias included in this version of the program
//This is a fast demo of the system, more work need to be done decomposing the parts of the net to make it accepting constructing the net
//with different kind of layers, deveritive matrix is essential to be included into it

// It's better to take hidden layers as an array of matrixs begin modifying codes - 2015-9-5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <unistd.h>
#include "simplenet.h"

int main()
{
    // Prepare data
    double **trainingData, **testData;

    int minTestPicNum = 100;
    readInMiniData(&trainingData, minTestPicNum);

    // Init the network
    struct SimpleNet myNet;
    // int inputSize = 724;
    int layerNum = 3;
    int *layerSizes = (int *)malloc(sizeof(int)*layerNum);
    layerSizes[0] = 724, layerSizes[1] = 100, layerSizes[2] = 10;
    initNetWork(&myNet, layerNum, layerSizes);

    // Test forward pass of the network
    forward(&myNet, trainingData[0]+1);
    int res = selectFromOutput(&myNet);
    printf("label: %lf, res: %d\n", trainingData[0][0], res);
    //TestForwardPass(trainingData, minTestPicNum, &myNet);

    // Params for learning, values below are kind of hand-tuned with no math directions which need improving
    double stepFactor = 0.003, minorDiff = 0.0001; //Set the parameter for M(i,j) = M(i,j) - stepParam*(Partial Derivative)

    int maxIteration = 50; //As they always set it to 50 in Currennt

    // Training by backprpagation
    //printf("\n%lf\n",(double)bp(&myNet, trainingData, minTestPicNum, stepFactor));
    return 0;
}