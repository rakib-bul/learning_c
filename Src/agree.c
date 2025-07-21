#include <stdio.h>

int main(void){
    char answer;

    printf("Do you agree? y/n >>");
    scanf("%c", &answer);

    if(answer == 'y' || answer == 'Y'){
        printf("You agreed");
    }
    else if (answer == 'n' || answer == 'N'){
        printf("You did not agree");
    }
    else{
        printf("Enter Correct answer");
    }

}
