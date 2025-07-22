#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    float celcius;
    float farenhiet;

    char mode;

    printf("Temperature Converter\n");
    printf("What do you want to convert?\n");
    printf("1. Farenhiet to Celcius - enter f \n");
    printf("2. Celcius to Farenhiet - enter c \n");
    scanf(" %c", &mode);

    if(mode == 'f'){
        printf("Enter the temperature in Farenhiet: ");
        scanf("%f", &farenhiet);
        celcius = (farenhiet - 32) * 5/9;
        printf("The temperature in Celcius is: %.2f", celcius);
    } else if(mode == 'c'){
        printf("Enter the temperature in Celcius: ");
        scanf("%f", &celcius);
        farenhiet = (celcius * 9/5) + 32;
        printf("The temperature in Farenhiet is: %.2f", farenhiet);
    }
    else{
        printf("Invalid input. Please enter 'f' or 'c'.");
    }
    return 0;

}