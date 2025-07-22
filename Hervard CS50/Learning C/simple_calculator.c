#include <stdio.h>
#include <math.h>

int main(){
    float value_1, value_2, result;
    char operator;

    printf("Enter the first value = ");
    scanf("%f", &value_1);

    printf("Enter Operator (*, +, - ,/)= ");
    scanf(" %c", &operator);

    printf("Enter the second value = ");
    scanf("%f", &value_2);


    //Calculation
    switch (operator)
    {
    case '+':
        result = value_1 + value_2;
        break;
    
    case '-':
        result = value_1 - value_2;
        break;

    case '*':
        result = value_1 * value_2;
        break;

    case '/':
        if (value_2 != 0){
            result = value_1 / value_2;
        }
        else{
            printf("Can't devide by Zero (0). \n");
            return 1;
        }
        break;

        default:
            printf("Error: Invalid operator!\n");
            return 1;

    }

    printf("Result %g \n", result);
    return 1;




}