#include <stdio.h>

int main(void){
    int array_size;

    // Enter Array size
    printf("Enter the size of the array =");
    scanf("%d", &array_size);

    int arr[array_size];

    //Input array_size
    printf("Enter %d elements for the array", array_size);
    for (int i = 0; i < array_size; i++){
        //printf("Enter %d elements for the array", array_size);
        scanf("%d", &arr[i]);
    }

    int biggest = arr[0];
    int smallest = arr[0];
    int diff;
    int sum = 0;


    //Finding biggest number

    for (int i = 1; i < array_size; i++){
        sum += arr[i];
        if (arr[i] > biggest){
            biggest = arr[i];
        }
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }


    printf("Biggest number in the array is %d \n", biggest);
    printf("Smallest number in the array is %d \n", smallest);
    printf("The Sum of the array is %d \n", sum);

    printf("The differance between the numbers are %d \n", diff = (biggest - smallest));

    return 0;
}
