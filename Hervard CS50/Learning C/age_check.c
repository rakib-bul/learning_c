#include<stdio.h>
#include<stdbool.h>


bool age_check(int age);

int main(){
    int age = 21;
    if(age_check(age)){
        printf("You are an adult\n");
    }
    else{
        printf("You must be 18+\n");
    }

}

bool age_check(int age){
    if(age>= 18){
        return true;

    }
    else{
        return false;
    }

}