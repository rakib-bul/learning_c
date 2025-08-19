#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int countdigit(int n);


int main(){
    int number;
    int cracker;
    int digits;
    long long attempts = 0;

    srand(time(NULL));

    printf("Enter the value of N: ");
    scanf("%d", &number);

    digits = countdigit(number);

    int lower = pow(10, digits-1);
    int higher = pow(10, digits)-1;

    printf("Cracking the number.....");
    clock_t start = clock();

    do{
        cracker = (rand()%(higher-lower+1))+lower;
        attempts += 1;
        printf("%d \n", cracker);
    }
    while(cracker != number);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Number cracked %d \n", cracker);
    printf("It took %lld attempts to crack \n", attempts);
    printf("Time taken %.6f seconds \n", time_taken);

    return 0;
}

int countdigit(int n){
    if (n==0){
        return 1;
    }
    int count = 0;

    while( n != 0){
        n = n/10;

        count++;
    }
    return count;
}
