#include <stdio.h>
#include <stdlib.h>

float addfunction(float x, float y) {

	float result = x + y;
	return result;
}

float subtractfunction(float x, float y) {
	float result = x - y;
	return result;
}

float multiplyfunction(float x, float y) {
	float result = x * y;
	return result;
}

float divisionfunction(float x, float y) {
	float result = x / y;
	return result;
}

const char *operationCase = NULL;

int main(int argc, const char ** argv) {



    
	float a = atof(argv[1]);
	operationCase = argv[2];
	float b = atof(argv[3]);
	switch ( *operationCase) {
		case '+':
			printf("Result: %.2f\n", addfunction(a, b));
			break;
		case '-':
			printf("Result: %.2f\n", subtractfunction(a, b));
			break;
		case 'x':
			printf("Result: %.2f\n", multiplyfunction(a, b));
			break;
		case '/':
			printf("Result: %.2f\n", divisionfunction(a, b));
			break;
		default:
			printf("Ups, try again\n");
			break;
	}
}