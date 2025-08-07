#include<stdio.h>

void sorted_list(int list[], int n);

int main()
{
    int list[] = {238, 541, 9832, 712, 4390, 1867, 94, 7821, 510, 2381, 6039, 356, 7291, 432, 899,1123,9012};
    int n = sizeof(list)/sizeof(list[0]);

    printf("Unsorted list :\n");

    for(int i = 0; i < n; i++){
        printf("%d, ", list[i]);
    }
    printf("\n");

    //print sorted list
    sorted_list(list, n);
    printf("Sorted list :\n");
    for(int j = 0; j<n;j++){
        printf("%d, ", list[j]);
    }
    printf("\n");

    return 0;
}

void sorted_list(int list[], int n){
    for(int i = 0; i<n; i++){
        int min_index = i;

        for(int j = i+1; j <n; j++){
            if(list[j]< list[min_index]){
                min_index = j;
            }
        }
        int temp = list[min_index];
        list[min_index] = list[i];
        list[i] = temp;
    }

}
