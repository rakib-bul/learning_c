#include <stdio.h>
#include <math.h>

int main(){
    double principal = 0.0;
    double rate = 0.0;
    int years = 0;
    int times_compounded = 0;
    double total = 0.0;

    printf("Interest Calculator \n");

    printf("Enter the Principal Amount (P):\n");
    scanf("%lf", &principal);

    printf("Enter the interest rate % (R): \n");
    scanf("%lf", &rate);
    rate = rate/100;

    printf("Enter the number of year (t): \n");
    scanf("%d", &years);

    printf("Enter the number of compound per year (N): \n");
    scanf("%d", &times_compounded);

    total = principal * pow(1 + rate / times_compounded, times_compounded * years);
    printf("After %d years the total amount will be %0.10lf BDT \n",years, total);


    return 0;
}
