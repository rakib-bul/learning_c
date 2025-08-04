#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char s[20];
    char t[20];  // Declare another string to hold the copy

    t[0] = toupper(t[0]);

    printf("S: ");
    scanf("%s", s);

    strcpy(t, s);  // Copy string s into t

    printf("T: %s\n", t);

    return 0;
}
