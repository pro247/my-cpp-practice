#include <iostream>
#include <random>

using namespace std;

int main()
{

    int guessNum = 0;

    cout << "Welcome to Random Number guessing game! \n";
    cout << "--------------------------------------------------\n";
    cout << "Game instructions\n";
    cout << "---------------------------------------------------\n";
    cout << "I will guess a number and you should try guessing the number, if the number is true you win\n";
    cout << "The guessed number should be within the range of 1 to 10 \n";
    cout << "Lets Go!\n";
    cout << "----------------------------------------------------\n";

    random_device rd;                        // for generating the seed
    mt19937 gen(rd());                       // Mersenne Twister engine
    uniform_int_distribution<> distr(1, 10); // Range [1, 10]

    // cout << "Please enter the guessed number:   ";
    // cin >> guessNum;

    do
    {
        cout << "Enter a number between 1 and 10: ";
        cin >> guessNum;

        // Input validation
        if (guessNum < 1 || guessNum > 10)
        {
            cout << "Invalid input. Please enter a number between 1 and 10.\n";
            continue; // Skip the rest and ask again
        }

        // Check if the guess is correct
        if (guessNum == distr(gen))
        {
            cout << "You win!\n";
            break; // Exit the loop
        }
        else
        {
            cout << "Try again.\n";
        }

    } while (true); // Loop until correct guess

    return 0;
}