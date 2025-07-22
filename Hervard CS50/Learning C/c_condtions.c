#include <stdio.h>

int main(){
    char first_person_name[20];
    char second_person_name[20];

    int first_person_age;
    int second_person_age;

    printf("Enter first person name >>");
    scanf("%s", &first_person_name);

    printf("Enter second person name >>");
    scanf("%s", &second_person_name);

    printf("Enter first person age >>");
    scanf("%d", &first_person_age);

    printf("Enter Second person age >>");
    scanf("%d", &second_person_age);

    if(first_person_age > second_person_age){
        printf("%s is older than %s", &first_person_name, &second_person_name);
    }
    else if(first_person_age < second_person_age){
        printf("%s younger than %s", &first_person_name, &second_person_name);
    }
    else{
        printf("Both are same age");
    }

    return 0;
}


