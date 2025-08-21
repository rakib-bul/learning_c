#include<stdio.h>


struct Player{
    char player_name[50];
    char gender[10];
    char race[10];
    char player_class[20];

};



int main(void){
    struct Player p;

    printf("Enter player name >> ");
    scanf("%s", &p.player_name);
    printf("Welcome %s \n", p.player_name);

}
