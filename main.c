#include <stdio.h>  //librairie
#include <stdlib.h> //librairie*
#include <string.h>

#define L_BOARD 7
#define H_BOARD 6


int nbrToken[L_BOARD] = {0, 0, 0, 0, 0, 0, 0};
char board[L_BOARD][H_BOARD] = {' '};

void display();
void printNbrToken();

int main(int argc, char *argv[])
{
    while (1) {
        display();
        int entreeUtilisateur = 0;
        printf("Ou voulez vous jouer votre jeton? ");
        scanf("%d", &entreeUtilisateur);
        int entreeBoard = entreeUtilisateur - 1;

        if (nbrToken[entreeBoard] == H_BOARD) {
            printf("Cette colonne est pleine, vous ne pouvez plus mettre de jeton ici :D\n");
            continue;
        }
        board[entreeBoard][nbrToken[entreeBoard]] = "X";
        nbrToken[entreeBoard]++;


        printNbrToken();

    }
   
    return 0;

}

void display() {
    printf("| | | | | | | |\n");
    printf("| | | | | | | |\n");
    printf("| | | | | | | |\n");
    printf("| | | | | | | |\n");
    printf("| | | | | | | |\n");
    printf("| | | | | | | |\n");
    printf("+-+-+-+-+-+-+-+\n");
    printf(" 1 2 3 4 5 6 7 \n");
}

void printNbrToken(){
    for (int i = 0; i < L_BOARD; i++) {
        printf("%d, ", nbrToken[i]);
    } 
    printf("\n");
}