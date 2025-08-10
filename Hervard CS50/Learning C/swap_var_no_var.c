#include<stdio.h>

int main(){
    int a = 20;
    int b = 40;

    a = a+b;
    b = a-b;
    a = a-b;


    printf("Value of A %d\n",a);
    printf("Value of B %d\n",b);
}
