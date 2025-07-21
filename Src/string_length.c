#include<stdio.h>

int main(){
    char name[10];
    printf("Enter your name >> ");
    scanf("%s", name);

    int n = 0;

    while (name[n] != '\0')
    {
        n++;
    }
    
    printf("Your name is %s \n", name);
    printf("%d \n", n);
    return 0;
}