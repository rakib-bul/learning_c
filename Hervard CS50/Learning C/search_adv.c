#include<stdio.h>
#include<string.h>

int main(){
    char strings[5][10] = {"Rakib", "Rifat", "Jami","Rohan","Ratri"};

    char s[5];

    printf("Enter name = ");
    scanf("%s", &s);


    for (int i = 0; i < 5; i++){
        if(strcmp(strings[i], s)==0){
            printf("Person Found \n");
            return 0;
        }
    }

    printf("Person not found \n");
    return 1;
}