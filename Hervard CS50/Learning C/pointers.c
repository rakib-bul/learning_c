#include<stdio.h>

int main(void){
    //Pointer = A variable that holds address of another varibale

    typedef char* string;

    string s = "Jami";
    int age = 21;
    int *page = &age;

    printf("%p\n", s[0]);
    printf("%p\n", s[1]);
    printf("%p\n", s[2]);
    printf("%p\n", s[3]);
    printf("%p\n", s[4]);
    printf("%p\n", s[5]);

    printf("%c\n", *s);
    printf("%c\n", *(s+3));

    printf("%s\n", s);

    printf("Address of Age %d \n", *page);
}