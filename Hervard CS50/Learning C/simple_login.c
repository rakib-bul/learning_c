#include<stdio.h>
#include<string.h>



int login(){
    char saved_username[]= "benga_kai";
    char saved_pass[]= "Playinggta5@2025";

    char user_name[50];
    char password[50];

    printf("Enter user name:");
    scanf("%49s", user_name);

    printf("Enter password:");
    scanf("%49s", password);


/* The strcmp() function is a fundamental string comparison function in C, declared in the <string.h> header*/
    if (strcmp(user_name, saved_username) == 0 && strcmp(password, saved_pass) == 0){
        printf("Logged in");
        return 1;
    }
    else{
        printf("Check username or password");
        return 0;
    }
    }


int main(){
    login();

    return 0;
}
