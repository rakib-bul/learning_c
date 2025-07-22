#include<stdio.h>

int main(){
    char choice = 'y';
    printf("Welcome to The Forest \n");
    printf("It's very silent in here. \n");
    printf("Do you want to go deeper? \n");
    scanf("%c", &choice);

    if (choice == 'y'){
        printf("You have entered the deep dark forest. \n");
        printf("It's very cold here.\n");
    }
    else{
        printf("Runnn! Runnn! RUn! \n");
    }

    return 0;

}