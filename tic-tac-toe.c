#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_player = 'X';

// Function to print the board
void print_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check if the current player wins
int check_winner() {
    for (int i = 0; i < SIZE; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full (draw)
int is_draw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return 0; // Still empty spots
            }
        }
    }
    return 1; // No empty spots, it's a draw
}

// Function to process a move
int make_move(int position) {
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return 0; // Invalid move
    }
   
    board[row][col] = current_player;
    return 1; // Valid move
}

// Main game loop
int main() {
    int position, moves = 0;

    printf("Tic Tac Toe Game\n");
    print_board();

    while (1) {
        printf("Player %c, enter your move (1-9): ", current_player);
        scanf("%d", &position);

        if (!make_move(position)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        print_board();
        moves++;

        if (check_winner()) {
            printf("Player %c wins!\n", current_player);
            break;
        }

        if (is_draw()) {
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}

