#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char player, char computer) {
    if (player == computer)
        return 0; // draw

    if ((player == 's' && computer == 'z') ||
        (player == 'z' && computer == 'p') ||
        (player == 'p' && computer == 's'))
        return 1; // player wins

    return -1; // computer wins
}

int main() {
    int n;
    char player, computer;
    int result;

    srand(time(NULL));
    n = rand() % 100;

    if (n < 33)
        computer = 's'; // stone
    else if (n < 66)
        computer = 'p'; // paper
    else
        computer = 'z'; // scissor

    printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
    scanf(" %c", &player); // note the space before %c

    result = game(player, computer);

    if (result == 0) {
        printf("\n\n\t\t\t\tGame Draw!\n");
    } else if (result == 1) {
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    } else {
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }

    printf("\t\t\t\tYou chose: %c and Computer chose: %c\n", player, computer);

    return 0;
}
