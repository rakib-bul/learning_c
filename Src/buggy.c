#include<stdio.h>

void print_column(int height);

int main(){
    int height;

    printf("Enter Height = ");

    scanf("%d", &height);

    print_column(height);
}


void print_column(int height){
    for (int i = 0; i < height; i++){
            printf("#\n");

    }
}
