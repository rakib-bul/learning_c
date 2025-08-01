#include<stdio.h>

int main(void){

    typedef char* string;

    string s = "Jami";

    printf("%p\n", s[0]);
    printf("%p\n", s[1]);
    printf("%p\n", s[2]);
    printf("%p\n", s[3]);
    printf("%p\n", s[4]);
    printf("%p\n", s[5]);

    printf("%c\n", *s);
    printf("%c\n", *(s+3));

    printf("%s\n", s);
}