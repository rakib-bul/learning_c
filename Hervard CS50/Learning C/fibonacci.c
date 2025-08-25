#include<stdio.h>

int main(void){
    int series_size = 10;

    if(series_size < 1){
        printf("Invalid Size\n");
    }
    else{
            int x = 0;
            int y = 1;

            printf("%d\n", x);
            if (series_size > 1) {
                printf("%d\n", y);
            }
            for(int i = 2; i<series_size; i++){
                int xy = x+y;

                printf("%d\n", xy);

                x = y;
                y = xy;
            }

    }

}
