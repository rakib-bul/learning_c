#include<stdio.h>

//Linear Search

int main() {

    int n;
    
    int numbers[] = {10, 20, 30, 40, 50,100, 129};

    printf("Enter a number to search: ");
    scanf("%d", &n);

    int i;
    for(i = 0; i < 7; i++){
        if(numbers[i] == n){
            printf("Number found \n");

            return 0;
        }
    }

    printf("Not found \n");

    return 1;
}