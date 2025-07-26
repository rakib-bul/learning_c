#include <stdio.h>
#include <string.h>


int main(void){
    char user_name[15];
    char names[3][15] = {"Rakib", "Jami", "Rohan"};
    char numbers[3][20] = {"+8801783924660", "+8801983590359", "+8801983838382"};

    printf("Enter Name: ");

    scanf("%14s", user_name);

    int found = 0;

    for (int i = 0; i < 3; i++){
        if (strcmp(user_name, names[i]) == 0){
            printf("Phone number : %s \n", numbers[i]);
            found = 1;
            break;
        }
    }

    if (!found){
        printf("Name not found \n");
    }

    return 0;
}