#include<stdio.h>
#include<string.h>

int main(){

    char noun[50] = "";
    char verb[50] = "";
    char adjective[50] = "";
    char adjective_2 [50] = "";
    char adjective_3 [50] = "";



    printf("Enter a noun (animal or person): \n");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun)- 1] = '\0';

    printf("Enter an adjective (description): \n");
    fgets(adjective, sizeof(adjective), stdin);
    adjective[strlen(adjective)- 1] = '\0';

    printf("Enter an adjective (description): \n");
    fgets(adjective_2, sizeof(adjective_2), stdin);
    verb[strlen(verb)- 1] = '\0';

    printf("Enter a verb (with ing): \n");
    fgets(verb, sizeof(verb), stdin);
    adjective_2[strlen(adjective_2)- 1] = '\0';

    printf("Enter an adjective (description): \n");
    fgets(adjective_3, sizeof(adjective_3), stdin);
    adjective_3[strlen(adjective_3)- 1] = '\0';


    //Story
    printf("\nToday I went to a %s zoo.\n", adjective);
    printf("In an exhibit I saw an %s.\n", noun);
    printf("%s was %s and %s! \n", noun, adjective_2, verb);
    printf("I was %s. \n", adjective_3);

    return 0;






    return 0;


}
