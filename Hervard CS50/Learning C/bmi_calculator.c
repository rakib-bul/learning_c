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
    scanf("%c", name);

    printf("Choose Your Gender : \n");

    for(int i = 0; i<2; i++){
        printf("%d. %s \n", i+1, gender[i]);
        scanf("%d", &gender_select;
    }
    if(gender_select >=1 && <= gender_select){

    }



    printf("Enter your height(ft)= ");
    scanf("%i", &feet);
    printf("Enter your height(in) = ");
    scanf("%i", &inch);
    printf("Enter your weight(kg) = ");
    scanf("%i", &weight);

    height = (((feet*12)+inch)/39.37);
    bmi = weight/(height * height);

    printf("You BMI is %lf",bmi);


}
