#include<stdio.h>

int main(){
    int a = 110;
    int b = 21;
    int c = 19;

    if(a > b || a > c){
        printf("A is the largest number");
    }
    else if(b > a || b > c){
        printf("B is the largest number");
    }
    else{
        printf("C is the largest number");
    }

    return 0;

}
