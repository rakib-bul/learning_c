#include<stdio.h>

int main(){
    int number = 0;

    for(int i = 0; i<100 ; i++){
        if(number%2 == 0){
            printf("%d \n", number);
        }

        number ++;
    }
    return 0;
}
