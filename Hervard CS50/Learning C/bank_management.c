#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Varibales
int account_id;
char first_name[50];
char last_name[50];
char father_name[100];
char mother_name[100];


//Functions
void create_account();

int main(){


    printf("Welcome to Benga Bank LTD \n");
    printf("......................... \n");

    create_account();
}


//Create Account

//User
void create_account(){
    //Generate Account ID
    srand(time(NULL));
    int min_value = 10000000;
    int max_value = 99999999;


    for(int i = 0; i<4; i++){
        account_id = (rand()%((max_value - min_value + 1))) + min_value;
        printf("%d %d \n",i+1, account_id);

    }


}

