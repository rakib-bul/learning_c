#include<stdio.h>
#include<math.h>

int main(){
    int lower_bound;
    int higher_bound;

    int is_prime;
    int prime_count = 0;

    printf("Enter the lower number: ");
    scanf("%d",&lower_bound);
    printf("Enter the higher number: ");
    scanf("%d", &higher_bound);

    printf("The prime numbers between %d & %d are:", lower_bound, higher_bound);

    for(int i = lower_bound; i<= higher_bound;i++){
        is_prime = 1;

        if(i<1){
            is_prime = 0;
        }
        else{
            for(int j = 2; j * j <= i; ++j){
                if(i % j == 0){
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime == 1){
            printf("%d ,", i);
            prime_count ++;
        }
    }
    printf("\n");
    printf("Total %d prime numbers found \n", prime_count);
    return 0;


}
