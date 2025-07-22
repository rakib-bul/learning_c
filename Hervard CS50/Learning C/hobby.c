#include <stdio.h>

int main(){
    char user_name[20];
    int user_age;
    char hobby[100];

    printf("Enter your name : \n");
    scanf("%19s", user_name);

    printf("Enter your age: \n");
    scanf("%d", &user_age);
    while (getchar() != '\n');



    printf("What's your hobby? \n");
    fgets(hobby, 100, stdin);

    printf("Hello, %s \n", user_name);
    printf("You are %d year old. \n", user_age);
    printf("Your hobby is %s.\n", hobby);

    return 0;
}