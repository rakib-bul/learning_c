#include <stdio.h>

/* format specifiers are special placeholders used in functions like printf(), scanf(), 
and similar input/output functions to indicate the type of data being handled.*/


int main(){
    int age = 25;
    float price = 25.567;
    double pi = 3.141592643589326;
    char symbol = '$';
    char name[]= "Rakib";


    printf("%d \n", age);
    printf("%f \n", price);
    printf("%f \n", pi);
    printf("%0.15f \n", pi);
    printf("%0.15lf \n", pi);
    printf("%c \n", symbol);
    printf("%s \n", name);

    return 0;


}