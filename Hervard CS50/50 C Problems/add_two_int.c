#include<stdio.h>

int main(){
    char operations[4][10] = {"Add", "Subtract", "Divide", "Multiply"};
    int choice;
    int number_a;
    int number_b;

    printf("Simple Calculator \n");
    printf("Choose your operation: \n");
    for(int i = 0; i<4; i++){
        printf("%d. %s \n", i+1, operations[i]);
    }
    scanf("%d", &choice);
    printf("Enter first number: ");
    scanf("%d", &number_a);
    printf("Enter Second number: ");
    scanf("%d", &number_b);

    switch(choice){
    case 1:
        int add = number_a + number_b;
        printf("%d", add);
        break;

    case 2:
        int subs = number_a - number_b;
        printf("%d", subs);
        break;
    case 3:
        if(number_b == 0){
            printf("Cannot divide with zero");
        }
        else{
            float div = (float)number_a / number_b;
            printf("%0.2f", div);

        }
        break;
    case 4:
        int mult = number_a * number_b;
        printf("%d", mult);
        break;
    default:
        printf("Enter correct choice");

    }
}
