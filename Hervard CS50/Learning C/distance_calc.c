#include<stdio.h>

int main(){
    float km;
    float mile;
    float km_convert = 1.609;
    float mile_convert = 0.621;
    int choice;
    printf("Distance Calculator");
    printf("What do you want to convert?\n");
    printf("1. Km to Mile\n");
    printf("2. Mile to KM\n");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter the KM = ");
        scanf("%f", &km);
        printf("%f miles\n", (km*mile_convert));
    }
    else if(choice == 2){
        printf("Enter the Mile = ");
        scanf("%f",&mile);
        printf("%f miles\n", (mile*km_convert));
    }
    else{
        printf("Enter correct value\n");
        return 1;
    }
}
