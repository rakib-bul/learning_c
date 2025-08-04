#include<stdio.h>

int main(){
    char name[30];
    char gender[2][10] = {"Male","Female"};
    float height;
    int feet;
    int inch;
    int weight;
    float bmi;
    int gender_select;

    printf("BMI Calculator\n");
    printf("Name= ");
    scanf("%s", name);

    printf("Choose Your Gender : \n");

    for(int i = 0; i<2; i++){
        printf("%d. %s \n", i+1, gender[i]);

    }
    scanf("%d", &gender_select);

    if(gender_select >=1 && gender_select<= 2){
        printf("%s\n",gender[gender_select-1]);
    }
    else{
        printf("Invalid Gender. Choose again. \n");
    }


    printf("Enter your height(ft)= ");
    scanf("%i", &feet);
    printf("Enter your height(in) = ");
    scanf("%i", &inch);
    printf("Enter your weight(kg) = ");
    scanf("%i", &weight);



    height = (((feet*12)+inch)/39.37);
    bmi = weight/(height * height);

    printf("Your BMI is %0.2f\n",bmi);

    if (bmi < 16)
        printf("Category: Severely Underweight\n");
    else if (bmi >= 16 && bmi < 17)
        printf("Category: Moderately Underweight\n");
    else if (bmi >= 17 && bmi < 18.5)
        printf("Category: Mildly Underweight\n");
    else if (bmi >= 18.5 && bmi < 25)
        printf("Category: Normal Weight\n");
    else if (bmi >= 25 && bmi < 30)
        printf("Category: Overweight\n");
    else if (bmi >= 30 && bmi < 35)
        printf("Category: Obese Class I\n");
    else if (bmi >= 35 && bmi < 40)
        printf("Category: Obese Class II\n");
    else
        printf("Category: Obese Class III\n");

    return 0;


}
