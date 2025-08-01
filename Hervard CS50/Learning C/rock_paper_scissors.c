#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

void generate_computer_choice();
int computer_choice = 0;
int main(){

    char choice[3][10] = {"Rock", "Paper", "Scissor"};
    int player_input = 0;


    printf("Welcome to Rock, Paper, Scissors\n");

    for(int i = 0; i<3; i++){
        printf("%d. %s\n", i+1 , choice[i]);

    }
    printf("Enter Your choice >> ");

    scanf("%d", &player_input);



    if(player_input >= 1 && player_input <= 3){
        printf("%s\n", choice[player_input -1]);
    }
    else{
        printf("Fuck you");
        return 0;
    }

    generate_computer_choice();

    printf("Computer Choice = %s \n", choice[computer_choice]);



    //Game logic
    if (player_input-1 == computer_choice){
        printf("Draw \n");
    }
    else if((player_input == 1 && computer_choice == 2)||
            (player_input == 2 && computer_choice == 0)||
            (player_input == 3 && computer_choice == 1)){
                printf("You win \n");
            }
    else{
        printf("You lost \n");
    }



}


void generate_computer_choice(){
    srand(time(NULL));
    computer_choice = rand()%3;

}
