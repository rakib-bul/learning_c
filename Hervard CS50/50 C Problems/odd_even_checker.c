#include<stdio.h>

int main(void){
    int n;

    printf("Even Odd Checker\n");
    printf("Enter Number = ");
    scanf("%d", &n);

    if (n%2 == 0){
        printf("It's an even number\n");
    }
    else{
        printf("It's an odd number\n");
    }
}
