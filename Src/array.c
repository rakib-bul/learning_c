#include<stdio.h>

// array = is a data structure that can hold multiple values of the same data type

float average(int length, int array[]);

int main(){
    int qty;

    printf("Enter person number = ");
    scanf("%d", &qty);

    int age[qty];

    for (int i = 0; i < qty; i++)
    {
        printf("Enter age = ");
        scanf("%d", &age[i]);

    }

    printf("Average age is %.2f \n",average(qty, age));

    return 0;
}

float average(int length, int array[]){
    //Calculate value
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];

    }

    return sum/ (float) length;
}
