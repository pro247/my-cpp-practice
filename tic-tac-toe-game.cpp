#include <iostream>

using namespace std;

// globalariable declaring the board
char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// function prototypes
void displayBoard();
bool markBoard(int, char);
int checkWin();
void resetBoard();

int main()
{
    char playAgain;

    do
    {
        int player = 1;
        int choice;
        char mark;
        int gameStatus = -1;

        resetBoard(); // Set up board for new game
        cout << "\nWelcome to Tic-Tac-Toe!\n";

        // Game loop
        do
        {
            displayBoard();

            player = (player % 2 == 1) ? 1 : 2;
            mark = (player == 1) ? 'X' : 'O';

            cout << "Player " << player << " (" << mark << "), enter a number (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9)
            {
                cout << "Invalid input! Choose a number between 1 and 9.\n";
                continue;
            }

            if (markBoard(choice, mark))
            {
                gameStatus = checkWin();
                player++; // Only switch if move was valid
            }
            else
            {
                cout << "Cell already taken! Try again.\n";
            }

        } while (gameStatus == -1);

        displayBoard();

        if (gameStatus == 1)
        {
            cout << "Player " << ((player - 1) % 2 == 1 ? 1 : 2) << " wins!\n";
        }
        else
        {
            cout << "It's a draw!\n";
        }

        // Ask if user wants to play again
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}

// function definition for displaying the tic tac ttoe game board
void displayBoard()
{

    cout << "\n\n";
    cout << "   " << board[1] << " | " << board[2] << " | " << board[3] << "\n";
    cout << "  ---|---|---\n";
    cout << "   " << board[4] << " | " << board[5] << " | " << board[6] << "\n";
    cout << "  ---|---|---\n";
    cout << "   " << board[7] << " | " << board[8] << " | " << board[9] << "\n\n";
}

// Function to mark the board
bool markBoard(int choice, char mark)
{
    if (board[choice] == '1' + (choice - 1))
    {
        board[choice] = mark;
        return true;
    }
    else
    {
        return false;
    }
}
// Check for win, draw, or continue
int checkWin()
{
    // Winning combinations
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    if (board[4] == board[5] && board[5] == board[6])
        return 1;
    if (board[7] == board[8] && board[8] == board[9])
        return 1;
    if (board[1] == board[4] && board[4] == board[7])
        return 1;
    if (board[2] == board[5] && board[5] == board[8])
        return 1;
    if (board[3] == board[6] && board[6] == board[9])
        return 1;
    if (board[1] == board[5] && board[5] == board[9])
        return 1;
    if (board[3] == board[5] && board[5] == board[7])
        return 1;

    // Check for draw (no cells left)
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return -1; // Game still going
        }
    }
    return 0; // Draw
}

// Function to reset the board to initial state
void resetBoard()
{
    for (int i = 1; i <= 9; i++)
    {
        board[i] = '0' + i; // '1' to '9'
    }
}