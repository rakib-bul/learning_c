#include<stdio.h>

int main(){
    int number;
    int original;
    int reminder;

    printf("Enter Number = ");
    scanf("%d", &number);

    original = number;

    int reverse = 0;

    while(number != 0){
        reminder = number % 10;
        reverse = reverse * 10 + reminder;
        number /= 10;
    }
    if (original % 10 == 0) {
    printf("Reversed number = %d", reverse);

    while (original % 10 == 0) {
      printf("0");
      original /= 10;
    }
  } else {
    printf("Reversed number = %d", reverse);
  }

  return 0;
}
