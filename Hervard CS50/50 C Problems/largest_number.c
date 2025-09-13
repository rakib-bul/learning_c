#include<stdio.h>


int main(){
    int num[3] = {12, 13, 15};
    int largest = num[0];

    for(int i = 0; i < 3; i++){
        if(num[i] > largest){
            largest = num[i];
        }
    }
    printf("%d is the largest number.\n", largest);
}
