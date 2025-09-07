#include <stdio.h>
#include <stdbool.h>

int main(){
    int a;

    printf("Prime Number checker \n");
    printf("Enter your number = ");
    scanf("%d", &a);

    if(a <= 1){
        printf("Not a prime number \n");
        return 0;
    }

    bool is_prime = true;

    for (int i = 2; i * i <a; i++){
        if(a%i == 0){
            is_prime = true;
            break;
        }
    }

    if(is_prime == true){
        printf("It's a prime number\n");
    }
    else{
        printf("It's not a prime number\n");
    }
}
