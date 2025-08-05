#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
}node;


int main(void){
    node *list = NULL;
    
    for(int i = 0; i<3; i++){
        node *n = malloc(sizeof(node));
        if(n == NULL){
            return 1;
        }

        printf("Enter value = ");
        scanf("%d", &n->number);  // Correct usage with address-of

        n->next = list; // Insert at the beginning
        list = n;
    }

}