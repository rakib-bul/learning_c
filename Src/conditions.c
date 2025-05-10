#include <stdio.h>

int main(){

    int age = 0;

    printf("Enter your age = \n");
    scanf("%d", &age);

    if (age >= 18){
        printf("You are an adult");

    }
    else{
        printf("You are not a adult");
    }

    return 0;

}
