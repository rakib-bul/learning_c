#include<stdio.h>

int main(){
    int a;
    int b;
    int c;

    printf("Enter the value of a = ");
    scanf("%d", &a);
    printf("Enter the value of b = ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("A = %d \n", a);
    printf("B = %d \n", b);
}
