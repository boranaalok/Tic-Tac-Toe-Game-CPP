#include <iostream>
using namespace std;

// Display the game board
void displayBoard(char board[3][3]) {
    cout << "\n";
    cout << "    TIC TAC TOE GAME\n";
    cout << "==========================\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2) {
                cout << " | ";
            }
        }

        cout << "\n";

        if (i < 2) {
            cout << "---|---|---\n";
        }
    }

    cout << "=========================\n";
}

// Check if a player has won
bool checkWin(char board[3][3], char player) {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {
            return true;
        }
    }

    // Check main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    // Check other diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

// Check if the board is full
bool checkDraw(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

// Main game function
void playGame() {

    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char player = 'X';
    int choice;
    int row, col;

    while (true) {

        displayBoard(board);

        cout << "\nPlayer " << player
             << ", enter your choice (1-9): ";

        cin >> choice;

        // Validate input
        if (cin.fail() || choice < 1 || choice > 9) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid choice! Try again.\n";
            continue;
        }

        // Convert choice into row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if position is already occupied
        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {

            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's symbol
        board[row][col] = player;

        // Check winning condition
        if (checkWin(board, player)) {

            displayBoard(board);

            cout << "\nCongratulations! Player "
                 << player << " Wins!\n";

            break;
        }

        // Check draw condition
        if (checkDraw(board)) {

            displayBoard(board);

            cout << "\nThe game is a draw!\n";

            break;
        }

        // Switch player
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
}

// Main function
int main() {

    char replay;

    cout << "Welcome to Tic Tac Toe!\n";

    do {

        playGame();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "\nThank you for playing!\n";

    return 0;
}