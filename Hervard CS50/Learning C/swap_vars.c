#include<stdio.h>

int main(){
    int a = 10;
    int b = 20;
    int temp;
    // Using 3rd variable
    temp = a;
    a = b;
    b = temp;

    printf("%d A \n", a);
    printf("%d B \n", b);
}
