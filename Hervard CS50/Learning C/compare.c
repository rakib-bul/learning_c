#include<stdio.h>
#include<string.h>

int main(){

    char a[20];
    char b[20];
    printf("Enter A = ");
    scanf("%19s", a);
    printf("Enter B = ");
    scanf("%19s", b);
    
    if (strcmp(a, b) == 0)
    {
        printf("They are same\n");
    }
    else{
        printf("They are not same \n");
    }
    
}