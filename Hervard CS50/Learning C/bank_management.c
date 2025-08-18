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
char present_address[100];
char permanent_address[100];
char address_selector;




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

    printf("Enter First Name: ");
    scanf("%s", &first_name);

    printf("Enter Last name: ");
    scanf("%s", &last_name);

    printf("Enter Father's name: ");
    scanf("%s", &father_name);

    printf("Enter mother's name: ");
    scanf("%s", &mother_name);

    printf("Present Address: ");
    scanf("%s", present_address);

    while (getchar() != '\n');
    

    printf("Is permanent & present address same? y/n >> ");
    scanf("%c", &address_selector);

    if (address_selector == "y" || "Y"){
        strcpy(permanent_address,present_address);
        printf("%s\n", permanent_address);
    }
    else{
        printf("Enter correct value\n");
    }




}

