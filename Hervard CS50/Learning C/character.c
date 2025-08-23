#include <stdio.h>
#include <string.h>

struct Player {
    char player_name[50];
    char player_gender[10];
    char race[10];
    char player_class[20];
};

int main(void) {
    struct Player p;
    char classes[5][20] = {"Warrior", "Mage","Knight","Thief","Rouge"};
    char gender[2][10] = {"Male", "Female"};
    int gender_choice;
    int class_choice;

    //Player Name
    printf("Enter player name: ");
    scanf("%49s", p.player_name);

    //Player Gender Section
    printf("Choose your gender(1/2):\n");
    for(int i=0; i<2; i++){
        printf("%d. %s \n", i+1, gender[i]);
    }
    do{
        if (scanf("%d", & gender_choice) !=1)
        {
            printf("Select a vaild option.(1/2)\n");
        }
        else if(gender_choice < 1 || gender_choice > 2){
            printf("Select an vaild option.(1/2)\n");
        }
        else{
            break;
        }
    }while (1);
    strcpy(p.player_gender, gender[gender_choice-1]);


    //Player Class
    printf("Choose your class(1-5): \n");
    for(int i = 0; i<5; i++){
        printf("%d. %s \n", i+1, classes[i]);
    }
    scanf("%d", &class_choice);
    strcpy(p.player_class, classes[class_choice-1]);




    printf("Welcome %s\n", p.player_name);
    printf("Your gender is %s \n", p.player_gender);
    printf("Class: %s\n", p.player_class);


    return 0;
}
