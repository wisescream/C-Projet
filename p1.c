#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void newBoard(int n, int p, int* board) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        board[i] = rand() % p + 1;
    }
}

void display(int* board, int n) {
    printf("\n====================\n");
    printf("Current Board State:\n");
    printf("====================\n");
    for(int i = 0; i < n; i++) {
        printf("Square %d : ", i);
        for(int j = 0; j < board[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("====================\n\n");
}

int possibleSquare(int* board, int n, int i) {
    return 1 <= i && i < n && board[i] > 0;
}

int selectSquare(int* board, int n) {
    int i;
    printf("Select a square to move from: ");
    scanf("%d", &i);
    while(!possibleSquare(board, n, i)) {
        printf("Invalid square. Select again: ");
        scanf("%d", &i);
    }
    return i;
}

int possibleDestination(int* board, int n, int i, int j) {
    return 0 <= j && j < i && board[i] > 0;
}

int selectDestination(int* board, int n, int i) {
    int j;
    printf("Select a destination square to move to: ");
    scanf("%d", &j);
    while(!possibleDestination(board, n, i, j)) {
        printf("Invalid destination. Select again: ");
        scanf("%d", &j);
    }
    return j;
}

void move(int* board, int n, int i, int j) {
    board[j] += 1;
    board[i] -= 1;
}

int lose(int* board, int n) {
    for(int i = 0; i < n; i++) {
        if(board[i] > 0) {
            return 0;
        }
    }
    return 1;
}

int hasValidMoves(int* board, int n) {
    for(int i = 1; i < n; i++) {
        if(board[i] > 0) {
            return 1;
        }
    }
    return 0;
}

void jeu() {
    int n, p, player = 1;
    printf("Enter the number of squares on the board: ");
    scanf("%d", &n);
    printf("Enter the maximum number of pawns per square: ");
    scanf("%d", &p);
    int board[n];
    newBoard(n, p, board);
    while(1) {
        system("cls");
        printf("\n\n\n");
        printf("========================================\n");
        printf("It's Player %d's turn.\n", player);
        printf("========================================\n");
        display(board, n);
        if(!hasValidMoves(board, n)) {
            printf("No valid moves. Player %d wins!\n", player);
            break;
        }
        int i = selectSquare(board, n);
        int j = selectDestination(board, n, i);
        move(board, n, i, j);
        player = 3 - player;
    }
}

int main() {
    jeu();
    return 0;
}