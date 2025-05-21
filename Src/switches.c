#include <stdio.h>


int main(){
    //switch = Is an altervative to using if-else statements more efficiently.

    int dayoftheweek = 0;
    scanf("%d", dayoftheweek);

    switch(dayoftheweek){
        case 1:
            printf("Saturday");
            break;
        case 2:
            printf("Sunday");
            break;
        case 3:
            printf("Monday");
            break;

    };
}
