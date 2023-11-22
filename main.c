#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "data.h"

float rand_float() {
	return (float) rand() / (float) RAND_MAX;
}


#define data_len sizeof(data)/sizeof(data[0])

float loss (float w, float b) {
	float result = 0.0f;
	for (size_t i=0; i<data_len; i++) {
		float x = data[i][0];
		float y = x*w + b;
		float d = y - data[i][1];
		result += d*d;
	}
		result /= data_len;
		return result;
}

float forward (float input, float w, float b) {
	return (float) input*w + b;
}

typedef struct {
	float weight;
	float bias;
	float loss;
} model;

void print_model (model m) {
	printf("printing parameters from saved model\n");
	printf("model weight => %f \n", m.weight);
	printf("model bias   => %f \n", m.bias);
	printf("model loss => %f \n", m.loss);
}

int train () {
	float w = rand_float();
	float b = rand_float();
	float eps = 1e-3;
	float rate = 1e-4;

	for (size_t i=0; i<10*1000*1000; i++) {

		// forward pass
		float l = loss(w, b);
		printf("iteration %d, loss => %f \n", i, l);

		// bacward pass
		float dw = (loss(w+eps, b)-l)/eps;
		float db = (loss(w, b+eps)-l)/eps;

		//printf("loss => %f, dw => %f, db => %f \n", l, dw, db);

		// update
		w += -rate * dw;
		b += -rate * db;
	}
	printf("-------------------------\n");

	// saving model
	model m;
	m.weight = w;
	m.bias = b;
	m.loss = loss(m.weight, m.bias);

	// printing model
	print_model(m);

	// inference
	float input = 30.0;
	float inf = forward(input, m.weight, m.bias);
	printf("inference from model with input => %f is %f \n", input, inf);


	return 0;
}

float sigmoidf (float x) {
	return 1 / (1 + expf(-x));
}

int test_function () {
	printf("Testing out sigmoid function \n");
	for (size_t i=0; i<100; i++) {
		printf(" %d => %f \n", i, sigmoidf(i));
	}
	return 0;
}

int inference_model_1 () {

	float w = 0.019682;
	float b = -0.369570;
	float loss = 0.119326;

	float input = 43;
	float inf = input*w + b;
	printf("inference from model with input => %f is %f \n", input, inf);
	printf("applying sigmoid on output => %f \n", sigmoidf(inf));
	return 0;

}

int main () {

	// train model 
	train();

	return 0;
}