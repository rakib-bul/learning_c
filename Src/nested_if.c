#include <stdio.h>
#include <stdbool.h>


int main(){
    float price = 10.00;
    bool is_student = false;
    bool is_senior = false;

    int answer;

    printf("Are you a student or Senior?\n");
    printf("Enter 1 for student \n");
    printf("Enter 2 for senior \n");
    scanf("%d", &answer);

    if (answer == 1){
        is_student = true;
    }
    else if (answer == 2)
    {
        is_senior = true;
    }
    

    if(is_student == true){
        printf("You get a discount of 10% \n");
        price *= 0.9;
    }
    else if (is_senior == true)
    {
        printf("You are a senior. \n");
        printf("You get a discount of 20%");
        price *= 0.8;
    }
    
    
    else{
        printf("No discount");
    }

    printf("The price of a ticket is %.2f $ \n", price);

    return 0;

}
