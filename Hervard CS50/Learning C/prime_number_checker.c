#include<stdio.h>
#include<stdbool.h>


bool is_prime(int n);

int main(){
    int number;

    printf("Enter the number \n");
    scanf("%d", &number);

    if (is_prime(number) == true){
        printf("%d is a prime number", number);
    }
    else{
        printf("%d is not a prime number", number);
    }
}

bool is_prime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i<n; i++){
        if(n % i == 0){
            return false;
        }

    }
    return true;

}

