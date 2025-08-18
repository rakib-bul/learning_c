#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int countdigit(int n);


int main(){
    int number;
    int cracker;

    srand(time(NULL));

    printf("Enter the value of N: ");
    scanf("%d", &number);

    cracker = rand()%countdigit(number);

    if ( cracker != number){
        while(cracker != number){
            cracker = rand()%countdigit(number);

            printf("%d \n", cracker);
        }
    }
    else{
        printf("Number cracked");
    }



    printf("The size of N is %d",countdigit(number));
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
