#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare Functions
void character_name();
void player_classes();

// Variables
char name[48];
char classes[4][10] = {"Warrior", "Mage", "Archer", "Rogue"};

int main(){
    character_name();
    player_classes();

    return 0;
}



void character_name(){
    //char name[10];
    printf("Welcome to the Character creator \n");
    printf("Enter your name = ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';
    printf("Welcome %s . How are you? \n", name);
}

void player_classes(){

    int choice;

    printf("Please choose your class (1/2/3/4) >> \n");
    for (int i = 0; i < 4; i++){
        printf("%d. %s \n", i+1, classes[i]);
    }
}
