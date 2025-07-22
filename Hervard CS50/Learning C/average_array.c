#include<stdio.h>

int main(void){
    int n;

    printf("Enter the size of array =");
    scanf("%d",&n);

    int arr[n];



    printf("Enter the %d elements of array = ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float average = 0.0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
        average = sum/n;

    }
    printf("The average of the array is %f", average);

    return 0;
}
