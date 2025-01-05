#include <iostream>
#include <string>
#include <limits> // For clearing input
using namespace std;

int main() {
    // Game board setup
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerA = 'X';
    const char playerB = 'O';
    char currentTurn = playerA;
    int row = -1, col = -1;
    char gameWinner = ' ';

    for (int moves = 0; moves < 9; moves++) {
        // Display the game grid
        cout << "   |   |   " << endl;
        cout << " " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << endl;
        cout << "   |   |   " << endl;

        if (gameWinner != ' ') {
            break;
        }

        // Prompt player input
        cout << "Current turn: " << currentTurn << endl;
        while (true) {
            cout << "Enter row and column (0-2): ";
            cin >> row >> col;

            // Validate input
            if (cin.fail()) {
                cout << "Invalid input! Please enter integers only." << endl;
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue;
            }

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid position! Row and column must be between 0 and 2." << endl;
            } else if (grid[row][col] != ' ') {
                cout << "This cell is already occupied! Try again." << endl;
            } else {
                break; // Valid input
            }
        }

        // Update the grid
        grid[row][col] = currentTurn;
        currentTurn = (currentTurn == playerA) ? playerB : playerA;

        // Check for a winner
        // Rows
        for (int r = 0; r < 3; r++) {
            if (grid[r][0] != ' ' && grid[r][0] == grid[r][1] && grid[r][1] == grid[r][2]) {
                gameWinner = grid[r][0];
                break;
            }
        }

        // Columns
        for (int c = 0; c < 3; c++) {
            if (grid[0][c] != ' ' && grid[0][c] == grid[1][c] && grid[1][c] == grid[2][c]) {
                gameWinner = grid[0][c];
                break;
            }
        }

        // Diagonals
        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            gameWinner = grid[0][0];
        } else if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            gameWinner = grid[0][2];
        }
    }

    // Display the result
    cout << "   |   |   " << endl;
    cout << " " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << endl;
    cout << "   |   |   " << endl;

    if (gameWinner != ' ') {
        cout << "Player " << gameWinner << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
