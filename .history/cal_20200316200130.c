#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

float subOperation(float x, float y) {
    return x - y;
}
float addOperation(float x, float y) {
    return x + y;
}
float mulOperation(float x, float y) {
    return x * y;
}
float divOperation(float x, float y) {
    return x / y;
}



int main(int argc,const char ** argv) {
    float a = atof(argv[1]);
    char Operator = argv[2];
    float b = atof(argv[3]);
    switch (Operator){
    case '*':
            printf("your asd is: %.2f\n",);
        break;
    case '/':
            printf("your asd is: %.2f\n",);
        break;
    case '+':
            printf("your asd is: %.2f\n",);
        break;
    case '-':
            printf("your asd is: %.2f\n",);
        break;
    default:
        printf("check your arguments\n");
        break;
    }
}