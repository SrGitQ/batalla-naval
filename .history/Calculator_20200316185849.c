#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int i;
    int numberX = 1;
    int operator = 2;
    int numberY = 3;
    float total;
    printf("%s\n",*argv);
    for (i = 0; i < argc--/2; i++){
        
    }
    



	float a = atof(argv[numberX]);
	operationCase = argv[operator];
	float b = atof(argv[numberY]);
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