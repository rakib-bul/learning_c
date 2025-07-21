#include<stdio.h>
#include<string.h>


int main(){
    int age = 0;
    char name[20] ="" ;

    printf("Enter your name: ");
    scanf("%19s", name);
    printf("\n Enter your age: \n");
    scanf("%d", &age);

    if (age >= 18){
        printf("Your name is %s and you are %d years old. \n", name, age);
        printf("You are and adult");
    }
    else if (age >= 0){
        printf("Your name is %s and you are %d years old. \n", name, age);
        printf("You are and child");
    }
    else{
        printf("Enter correct value");

    }

    return 0;




}
