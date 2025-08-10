#include<stdio.h>


int main(){
    float c;
    float f;

    int choice;

    printf("What do you want to convert?\n");
    printf("1. Celcius to Farenhiet\n");
    printf("2. Farenheit to Celcius\n");
    scanf("%d",&choice);

    if(choice == 1){
        printf("Enter the value of Celsius = ");
        scanf("%f", &c);
        printf("The temperature is %0.2f degree Fahrenheit.", (c*1.8+32));
    }
    else if(choice == 2){
        printf("Enter the value of Fahrenheit = ");
        scanf("%f", &f);
        printf("The temperature is %0.2f degree Celsius.", ((f-32)*5/9));
    }
    else{
        printf("Invaild Command");
    }


}
