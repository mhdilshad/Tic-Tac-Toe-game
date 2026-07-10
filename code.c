// Configuration & State:>
    












//UI Rendering:>
void draw_board() {

   
    system("cls");


    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}




//Core Logic:>
// Places a marker on the board if the slot is available
int place_marker(int slot) {
    // Check if the slot is valid and hasn't been taken by 'X' or 'O'
    if (slot < 1 || slot > 9 || board[slot] == PLAYER_X || board[slot] == PLAYER_O) {
        return 0; // Invalid move
    }

    board[slot] = current_marker;
    return 1; // Valid move
}

// Checks rows, columns, and diagonals for a win
// Returns 1 if someone won, 0 otherwise
int check_winner() {
    // Rows
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    if (board[4] == board[5] && board[5] == board[6]) return 1;
    if (board[7] == board[8] && board[8] == board[9]) return 1;

    // Columns
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    if (board[3] == board[6] && board[6] == board[9]) return 1;

    // Diagonals
    if (board[1] == board[5] && board[5] == board[9]) return 1;
    if (board[3] == board[5] && board[5] == board[7]) return 1;

    return 0;
}










//Main Game Loop:>








