#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char s[100];

    printf("Enter string = ");

    fgets(s, sizeof(s), stdin);

    for (int i = 0; i <strlen(s); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            printf("%c", s[i] - ('a' - 'A'));
        }
        else{
            printf("%c", s[i]);
        }

        printf("\n");
    }
}