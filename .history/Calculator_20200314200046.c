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
	float num1 = atof(argv[1]);
	operationCase = argv[2];
	float num2 = atof(argv[3]);
	switch ( *operationCase) {
		case '+':
			printf("Result: %.2f\n", addfunction(num1, num2));
			break;
		case '-':
			printf("Result: %.2f\n", subtractfunction(num1, num2));
			break;
		case 'x':
			printf("Result: %.2f\n", multiplyfunction(num1, num2));
			break;
		case '/':
			printf("Result: %.2f\n", divisionfunction(num1, num2));
			break;
		default:
			printf("Ups, try again\n");
			break;
	}

}