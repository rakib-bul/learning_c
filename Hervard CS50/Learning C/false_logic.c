#include <stdio.h>
#include <math.h>

int main(){
    float a = 0.1f;
    float b = 0.2f;
    float sum;

    sum = a+b;

    if (sum == 0.3){
        printf("0.1 and 0.2 is equal to 0.3");
    }
    else{
        printf("0.1 and 0.2 is not equal to 0.3");
        printf("%f", sum);
    }
}
