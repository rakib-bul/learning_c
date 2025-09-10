#include<stdio.h>

int main(){

    int min_num;
    int max_num;

    printf("Even Number finder \n");
    printf("Enter min number >> ");
    scanf("%d", &min_num);

    printf("Enter max number >> ");
    scanf("%d", &max_num);
    printf("Even Numbers are:\n");
    for(int i = min_num; i<max_num; i++){
        if(i%2 == 0){

            printf("%d ,", i);
        }
    }

}
