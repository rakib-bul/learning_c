#include<stdio.h>

void love(void){
    printf("I love you");
}



int main(){
    int count;
    scanf("%d", &count);

    while(count > 0){
        love();
        count = count -1;
        printf("%d \n", count);
;        //count = count -1;
    }
}
