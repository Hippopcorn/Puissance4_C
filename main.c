#include <stdio.h>  //librairie
#include <stdlib.h> //librairie*

#define L_BOARD 7
#define H_BOARD 6

int nbrToken[L_BOARD] = {0, 0, 0, 0, 0, 0, 0};
char board[L_BOARD][H_BOARD] = {
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}};

void display();
void printNbrToken();
int checkWin(int x);
int checkVertival(int x, int y);
int checkHorizontal(int x, int y);
int checkDiagonalRight(int x, int y);
int checkDiagonalLeft(int x, int y);

int main() {
    int round = 1;
    while (1) {
        display();
        int entreeUtilisateur = 0;
        printf("Ou voulez vous jouer votre jeton?\n");
        scanf("%d", &entreeUtilisateur);

        if (entreeUtilisateur < 1 || entreeUtilisateur > 7) {
            printf("Entrez un numero de colonne valide svp :D\n");
            continue;
        }

        int entreeBoard = entreeUtilisateur - 1;

        if (nbrToken[entreeBoard] == H_BOARD) {
            printf("Cette colonne est pleine, vous ne pouvez plus mettre de jeton ici :D\n");
            continue;
        }

        if (round % 2 == 0) {
            board[entreeBoard][nbrToken[entreeBoard]] = 'O';
        } else {
            board[entreeBoard][nbrToken[entreeBoard]] = 'X';
        }

        if (checkWin(entreeBoard)) {
            display();
            printf("C'est gagne !\n");
            return 0;
        }

        nbrToken[entreeBoard]++;

        round++;
    }

    return 0;
}

void display() {
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][5], board[1][5], board[2][5], board[3][5], board[4][5], board[5][5], board[6][5]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][4], board[1][4], board[2][4], board[3][4], board[4][4], board[5][4], board[6][4]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][3], board[1][3], board[2][3], board[3][3], board[4][3], board[5][3], board[6][3]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][2], board[1][2], board[2][2], board[3][2], board[4][2], board[5][2], board[6][2]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][1], board[1][1], board[2][1], board[3][1], board[4][1], board[5][1], board[6][1]);
    printf("|%c|%c|%c|%c|%c|%c|%c|\n", board[0][0], board[1][0], board[2][0], board[3][0], board[4][0], board[5][0], board[6][0]);
    printf("+-+-+-+-+-+-+-+\n");
    printf(" 1 2 3 4 5 6 7 \n");
}

void printNbrToken() {
    for (int i = 0; i < L_BOARD; i++) {
        printf("%d, ", nbrToken[i]);
    }
    printf("\n");
}

int checkWin(int x) {    //  x = entree utilisateur -1
    int y = nbrToken[x]; // y = nbr de jetons en colonne de l'entree utilisateur

    if (checkVertival(x, y) || checkHorizontal(x, y) || checkDiagonalRight(x, y) || checkDiagonalLeft(x, y)) {
        return 1;
    }

    return 0;
}

int checkVertival(int x, int y) {
    if (y < 3) {
        return 0;
    }

    for (int i = y - 1; i >= y - 3; i--) {
        if (board[x][y] != board[x][i]) {
            return 0;
        }
    }

    return 1;
}

int checkHorizontal(int x, int y) { // board[0 a 6][y] = ligne a checker
    int count = 0;
    char charToCheck = board[x][y];

    for (int i = 0; i < L_BOARD - 1; i++) {
        if (board[i][y] == charToCheck) {
            count++;

            if (count == 4) {
                return 1;
            }
        } else {
            count = 0;
        }
    }

    return 0;
}

int checkDiagonalRight(int x, int y) {
    int count = 0;
    int ToCheck = 0;
    char charToCheck = board[x][y];

    if (y <= x) {
        for (int xToCheck = x - y; xToCheck < L_BOARD && ToCheck < H_BOARD; xToCheck++) {
            if (board[xToCheck][ToCheck] == charToCheck) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
            ToCheck++;
        }

    } else {
        for (int yToCheck = y - x; yToCheck < H_BOARD && ToCheck < L_BOARD; yToCheck++) {
            if (board[ToCheck][yToCheck] == charToCheck) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
            ToCheck++;
        }
    }

    return 0;
}

//  x = entree utilisateur -1
// y = nbr de jetons en colonne de l'entree utilisateur

int checkDiagonalLeft(int x, int y) {
    int count = 0;
    int ToCheck = 0;

    char charToCheck = board[x][y];

    if (y <= 6 - x) {
        for (int xToCheck = x + y; xToCheck >= 0 && ToCheck <= H_BOARD; xToCheck--) {
            if (board[xToCheck][ToCheck] == charToCheck) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
            ToCheck++;
        }
    } else {
        ToCheck = 6;

        for (int yToCheck = y - (6 - x); yToCheck < H_BOARD && ToCheck >= 0; yToCheck++) {
            if (board[ToCheck][yToCheck] == charToCheck) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
            ToCheck--;
        }
    }

    return 0;
}
