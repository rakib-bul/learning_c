#include<stdio.h>


int count_digit(int n);

int main(){
    int n;

    printf("Enter your number: ");
    scanf("%d", &n);

    printf("%d", count_digit(n));

}

int count_digit(int n){
    if(n == 0){
        return 1;
    }
    int count = 0;

    while(n != 0){
        n = n/10;
        count+= 1;
    }
    return count;
}
