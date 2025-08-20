#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>

//Global Variables
char tree_name[5][10] = {"Oak","Spruce", "Brich", "Maple","Acacia"};
int cutting_xp = 10;
int axe_power = 10;
int axe_hp = 200;
int tree_hp = 50;
int tree_choice;
int cut_count = 0;
int inventory[5]= {0,0,0,0,0};
int total_xp = 0;


//Functions
void wood_cutting();


int main(void){
    //Start
    printf("Welcome to Tree Cutting Simulator.\n");
    printf("Cut trees in the virtual world.\n");
    for(int i = 0; i<5; i++){
        printf("%d. %s \n",i+1, tree_name[i]);
    }


    do{
        printf("Select a tree to cut 1-5. \n");

        if(scanf("%d", &tree_choice) != 1){
            printf("Invalid Input. Please enter a number from 1-3\n");
        }
        else if(tree_choice < 1 || tree_choice > 5){
            printf("Invalid Input. Please enter a number from 1-3\n");
        }
        else{
            break;
        }

    } while(1);

    printf("Your choice is %s \n", tree_name[tree_choice-1]);



    wood_cutting();

}

void wood_cutting(){

    while (axe_hp > 1 && tree_hp > 0){
        int current_hp = tree_hp;
        while(current_hp > 0 && axe_hp > 0){
            current_hp -= axe_power;
            axe_hp -= 3;
            cut_count++;
            printf("# ");
            Sleep(1000);


        } printf(" \n");
        if(current_hp == 0){
            int gained_xp = cut_count*cutting_xp;
            total_xp += gained_xp;
            inventory[tree_choice-1]+= 1;

            printf("%d hits used to cut the tree\n", cut_count);
            printf("Axe health = %d \n", axe_hp);
            printf("You have gained %d XP\n", (gained_xp));
            printf("Your total XP is %d \n", total_xp );
            printf("%d %s logs in inventory.\n", inventory[tree_choice-1], tree_name[tree_choice-1]);

            cut_count = 0;

            if(axe_hp < 0){
                printf("Snap!! the axe broke!/n");
                return;
            }


        }
        else{
            printf("Can not cut the tree \n");
        }



    }
}
