#include<stdio.h>

int main(){
    int n;

    printf("Enter number = ");
    scanf("%d",&n);

    int calc;
    calc = n%2;

    if(calc == 0){
        printf("It's a Even number \n");
    }
    else{
        printf("It's an odd number \n");
    }
}
