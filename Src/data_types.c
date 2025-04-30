#include<stdio.h>
#include<stdbool.h>

int main(){
    char a = 'c'; // single character %c
    char b[] = "Rakib"; // String %s or array of characters

    float c = 3.14159265358979323846; // 4 bytes 32 bit of precision 6-17 digit %f
    double d = 3.14159265358979323846; // 8 bytes 64 bit of precision 15-16 digits %lf

    bool e = true; //1 byte true or false






    // Testing data types
    printf("%s", b);
    printf("%0.15f \n", c);
    printf("%0.15lf \n", d);
    return 0;

}