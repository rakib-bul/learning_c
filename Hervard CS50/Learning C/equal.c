#include <stdio.h>
#include <math.h>

int main(){
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;

    double total = a+b;
    printf("%0.17f \n", c);
    printf("%0.17f \n", total);

    if (total == c){
        printf("a+b = c");
    }
    else{
        printf("Not Equal to C");
    }

    return 0;
}
