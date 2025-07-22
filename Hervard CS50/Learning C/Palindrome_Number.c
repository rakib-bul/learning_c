#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(long long x);

int main(){
    long long num;

    printf("Enter a number = ");
    scanf("%lld", &num);

    if (isPalindrome(num)){
        printf("%lld is a Palindrome number", num);
    }
    else{
        printf("%lld is not a Palindrome number", num);
    }

    return 0;
}


bool isPalindrome (long long x){
    if (x < 0 || (x%10 == 0 && x!= 0)){
        return false;
    }

    long long reversedHalf = 0;

    while (x > reversedHalf){
        reversedHalf = reversedHalf * 10 + x % 10;
        x = x/10;
    }


    //Check if palindrome
    if (x == reversedHalf || x == reversedHalf / 10){
        return true;
    }
    else{
        return false;
    }
}
