#include <stdio.h>
#include <stdbool.h>

int questions(){
    char user_name[20];
    int user_age;
    char answer;
    bool is_student;
    printf("Welcome to Self Practice 1 \n");
    printf("Enter your name :");
    scanf("%s", user_name);
    printf("Enter Your age : \n");
    scanf("%d", &user_age);
    printf("Are you a student? Y/N: ");
    scanf(" %c", &answer);

    printf("Hi, %s ! \n", user_name);
    if (answer == 'y'){
        printf("You are a student. \n");
    }
    else
    {
        printf("You are not a student. \n");
    }
    printf("You are %d", user_age ,"year old");
}

int main(){
    questions();
    return 0;
}