#include <stdio.h>
#include <math.h>

int main(){
    double radius = 0.0;
    double area = 0.0;
    const double pi = 3.14159

    printf("Enter the Radius: \n");
    scanf("%lf", &radius);
    area = pi * pow(radius, 2);
    printf("Area is %lf", area)




    return 0;
}
