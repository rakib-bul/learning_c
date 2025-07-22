#include<stdio.h>
#include<math.h>

int main(){
    //A variable is a allocated storage in a memory to store value

    int x;
    x = 12;
    int y = 5;

    int age = 25; //integer
    float gpa = 2.5; //floating point 
    char name[] = "Rakib"; // Array of characters
    char grade = 'C'; //Single character (fixed case and single quotes)
    
    printf("Hello %s! \n", name);
    printf("You are %d years old\n", age); // Added "years" and newline
    printf("Your GPA is %f \n", gpa); // Removed grade from this line
    printf("Your grade is %c\n", grade);
    
    // For division, you need to declare a variable and use the correct operator
    float division = (float)x / y; // For floating-point division
    printf("%f\n", division);
    
    int mod = x % y; // For integer modulus (remainder)
    printf("%d\n", mod);
    
    return 0; // Good practice to return from main
}