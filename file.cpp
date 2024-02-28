#include <iostream>
using namespace std;
// Function to draw Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    cout << "-----------------\n";
    for(int i = 0; i < 3; i++){
        cout << "| ";
        for(int j = 0; j < 3; j++){
            cout << board[i][j] <<  " | ";
        }
        cout << "\n--------------\n";
    }
}
// Function to check for a win
bool checkwin(char board[3][3], char player) {
    // Check rows, columns, and diagnoals
    for (int i=0; i<3; i++){
        if (board[i][0] == player && board[i][i] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main(){
    //Initialize the board and players
    char board[3][3] = { { ' ', ' ', ' '},
                         { ' ', ' ', ' '},
                         { ' ', ' ', ' '} };
    char player = 'x';
    int row, col;
    int turn; // Declare turn here
    
    cout << "Welcome to Tic-Tac-Toe\n";

    // Game loop
    for(turn = 0; turn < 9; turn++) {
        // Draw the Board
        drawBoard(board);

        // Prompt for valid input
        while(true) {
            cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2 ) { 
                cout << "Invalid Move. Try again.\n";
            }
            else { 
                break; // valid input, exit the loop.
            }
        }
        // make the move
        board[row][col] = player;

        //check for a win after making a move
        if (checkwin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            break; //Exit the loop after a win.
        }

        //switch to the other player
        player = (player == 'x')? '0' : 'x';
    }
    //End of the Game
    drawBoard(board);

    //check for a draw
    if ( turn == 9 && !checkwin(board, 'x') && !checkwin(board,'0')) {
        cout << "It's Draw!\n";
    }
    return 0;
}