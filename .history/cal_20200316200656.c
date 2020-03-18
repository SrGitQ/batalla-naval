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
    const char *Operator = argv[2];
    float b = atof(argv[3]);
    switch (*Operator){
    case 'x':
            printf("your multiplication is: %.2f\n", mulOperation(a,b));
        break;
    case '/':
            printf("your division is: %.2f\n", divOperation(a,b));
        break;
    case '+':
            printf("your addition is: %.2f\n", addOperation(a,b));
        break;
    case '-':
            printf("your subtraction is: %.2f\n", subOperation(a,b));
        break;
    default:
        printf("check your arguments\n");
        break;
    }
}