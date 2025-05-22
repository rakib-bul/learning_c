#include<stdio.h>

int main()
{
    int a = 12;
    int b = 14;
    // There are three logical operator in C
    printf("There are three logical operator in C \n");
    printf("Logical AND ( && ) \n");
    printf("Logical OR ( || ) \n");
    printf("Logical NOT (!) \n");
    printf("================ \n");
    printf("================ \n");


    // And Operator Example
    printf("And Operator \n");
    printf("================ \n");
    if(a > 0 && b > 0)
    {
        printf("Both are Greater than Zero. \n");
    }
    else{
        printf("Both are less than Zero. \n");
    }


    return 0;
}
