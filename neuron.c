#include "engine.h"

bool artificial_neuron(uint8_t byte, uint8_t weight, uint8_t threshold)
{	
	uint8_t dot_product = xnor_dot(byte, weight);
	return activation(dot_product, threshold);
}

int main()
{
	bool output = artificial_neuron(0b11001010, 0b11101100, 5);
	printf("Artificial Neuron output: %d\n", output);
}
