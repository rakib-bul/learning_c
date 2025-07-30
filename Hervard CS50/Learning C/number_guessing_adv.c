#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int guess;
    int attempts = 0;
    int max_attempts = 10;
    int random_number;

    srand((time(NULL)));

    random_number = (rand()%100)+1;

    printf("Welcome to number guessing game \n");
    printf("You have %d attemps. Choose any number 1 to 100 = ", max_attempts);

    while(attempts < max_attempts){
        scanf("%d", &guess);
        attempts ++;

        if (guess == random_number){
            printf("You have guessed the correct number \n");
            return 0;
        }
        else if( guess < random_number){
            printf("Attempt %d : Too low, Choose again \n", attempts);
        }
        else{
            printf("Attempt %d: Too high, choose again \n", attempts);
        }

    }
    printf("You are out of guess. The number was %d. \n", random_number);
    printf("Game over \n");

    return 0;
}
