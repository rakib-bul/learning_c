#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declare Functions
void character_name();
void player_classes();
void player_gender();

// Variables
char name[48];
char classes[4][10] = {"Warrior", "Mage", "Archer", "Rogue"};
char gender[2][10] = {"Male", "Female"};

int main(){
    character_name();
    player_classes();
    player_gender();

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

    int class_choice;

    printf("Please choose your class (1/2/3/4) >> \n");
    for (int i = 0; i < 4; i++){
        printf("%d. %s \n", i+1, classes[i]);
    }

    do {
        printf(">> ");
        scanf("%d", &class_choice);
        while (getchar() != '\n');
    } while (class_choice < 1 || class_choice > 4);

    printf("You have chosen %s. \n", classes[class_choice -1]);



}

void player_gender(){
    int gender_choice;

    printf("Choose Gender (1/2) >> \n");

    for (int i = 0; i < 2; i++){
        printf("%d. %s \n", i+1, gender[i]);
    }

    do{
        printf(">> ");
        scanf("%d", &gender_choice);
        while (getchar() != '\n');
    } while (gender_choice < 1 || gender_choice > 2);

    printf("You have chosen %s. \n", gender[gender_choice - 1]);
}


