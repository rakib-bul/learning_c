#include <stdio.h>
#include <string.h>  // Required for strcpy

int main(){
    float subject_1, subject_2, subject_3, subject_4;
    float total_marks, percentage;
    char grade[3];
    char name[50];

    //Enter Name
    printf("Enter Your name >> ");
    scanf("%s", name);

    //Input subject marks
    printf("Enter Mark for subject 1 out of 100 >> ");
    scanf("%f", &subject_1);

    printf("Enter Mark for subject 2 out of 100 >> ");
    scanf("%f", &subject_2);

    printf("Enter Mark for subject 3 out of 100 >> ");
    scanf("%f", &subject_3);

    printf("Enter Mark for subject 4 out of 100 >> ");
    scanf("%f", &subject_4);

    //Grade Calculation
    total_marks = subject_1 + subject_2 + subject_3 + subject_4;
    percentage = (total_marks / 400) * 100;

    //Grades
    if (percentage >= 80){
        strcpy(grade, "A+");
    }
    else if (percentage >= 70){
        strcpy(grade, "A");
    }
    else if (percentage >= 60){
        strcpy(grade, "A-");
    }
    else{
        strcpy(grade, "B");
    }

    //Display results
    printf("\n----- Results -----\n");
    printf("Student name: %s\n", name);
    printf("Total Marks: %.2f/400\n", total_marks);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %s\n", grade);

    return 0;
}
