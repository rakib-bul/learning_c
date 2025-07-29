#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int guess;
    int random_number;
    int attemp = 0;
    int max_attemp = 10;

    srand(time(NULL));

    random_number = (rand()%100)+1;

    printf("Welcome to number guessing game \n");
    printf("You have 10 attemps to find the number \n");

    while (attemp < max_attemp)
    {
        printf("Attemp %d : Enter your number = ", attemp +1);
        scanf("%d", &guess);
        attemp ++;

        if (random_number == guess){
            printf("You Guessed correct number. \n");
            printf("Your guessed number is %d \n", guess);

            return 0;
        }
        else if(random_number < guess){
            printf("Too high, guess again.\n");
        }
        else{
            printf("Too low, guess again.\n");
        }

    }
    printf("You have ran out of attemps. The number was %d", random_number);
        return 0;

}
