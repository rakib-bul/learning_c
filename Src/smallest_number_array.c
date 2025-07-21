#include <stdio.h>

int main(){
    int n;

    printf("Enter the number of Elements = ");
    scanf("%d", &n);

    int arr[n];

    //Input elements
    printf("Input %d number of elements", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Assume first number in the array is smallest
    int smallest = arr[0];

    for(int i = 1; i<n;i++){
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }

    printf("The smallest number in the array is %d", smallest);

    return 0;


}
