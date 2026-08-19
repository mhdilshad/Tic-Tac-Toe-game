// Configuration & State:>
#include <stdio.h>
#include <stdlib.h>

// Symbols for player representations
#define PLAYER_X 'X'
#define PLAYER_O 'O'


char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char current_marker;
int current_player;

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


int main() {
    current_player = 1;
    current_marker = PLAYER_X;
    int total_turns = 0;
    int game_status = 0; // 0 = Ongoing, 1 = Win, 2 = Draw
    int choice;

   //Main Game Loop:>
    while (game_status == 0) {
        draw_board();
        printf("Player %d (%c), enter a slot number (1-9): ", current_player, current_marker);

        // Validate user input is an integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            getchar(); // Pause
            continue;
        }

        // Try to place the marker
        if (!place_marker(choice)) {
            printf("Slot already taken or invalid! Press Enter to try again...");
            while (getchar() != '\n'); // Clear buffer
            getchar(); // Pause
            continue;
        }

        total_turns++;

        // Check for game over conditions
        if (check_winner()) {
            game_status = 1; // Someone won
        } else if (total_turns == 9) {
            game_status = 2; // Board full, it's a draw
        } else {
            // Swap players
            current_player = (current_player == 1) ? 2 : 1;
            current_marker = (current_marker == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // Final Render and Winner Announcement
    draw_board();
    if (game_status == 1) {
        printf("Congratulations! Player %d (%c) wins!\n", current_player, current_marker);
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}
