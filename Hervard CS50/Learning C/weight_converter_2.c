#include <stdio.h>

int main(){
    int choice = 0;
    float kilo_gram = 0.0f;
    float pound = 0.0f;

    printf("Weight Converter \n");
    printf("1. Kilograms to Pounds \n");
    printf("2. Pounds to Kilograms \n");
    scanf("%d", &choice);

    if (choice == 1){
        printf("Enter the weight in Kilograms:");
        scanf("%f", &kilo_gram);
        pound = kilo_gram * 2.20462;
        printf("The weight is %.2f pounds. \n", pound);
    }
    else if (choice == 2){
        printf("Enter the weight in Pounds:");
        scanf("%f", &pound);
        kilo_gram = pound / 2.20462;
        printf("The wight is %.2f pounds. \n", kilo_gram);
    }
    else{
        printf("Enter a valid choice");
    }

    return 0;
}
