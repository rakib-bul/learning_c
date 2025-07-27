#include <stdio.h>
#include <string.h>


typedef struct{
    char name[20];
    char number[20];
} person;


int main(void){

    char name_input[20];
    person people[3];

    strcpy(people[0].name , "Jami");
    strcpy(people[0].number , "+8801783924660");

    strcpy(people[1].name, "Benga");
    strcpy(people[1].number, "0176969696");

    strcpy(people[2].name,  "Kai");
    strcpy(people[2].number, "+178943898");

    printf("Enter name : ");
    scanf("%s", name_input);

    for (int i = 0; i < 3; i++){
        if (strcmp(people[i].name, name_input)== 0){
            printf("Found %s \n", people[i].number);

            return 0;
        }

        printf("Not Found \n");
        return 0;
    }

}