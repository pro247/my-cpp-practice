// This will will get grades for six modules from students then iw will display the average GPA for thestude
// if the student has failed the program will also notfy the user an tell them to work hard
// if the student has passed it will also tell the user and congratulate them
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// function prototypes
double convertToGPA(double);
double calculateAverageGPA(const std::vector<double> &);
void explainGPAConversion();

int main()
{

    int numModules;
    int choice;
    cout << "Enter number of modules: ";
    cin >> numModules;

    // Clear newline from cin buffer after reading an int
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> moduleNames(numModules);
    vector<double> scores(numModules);

    for (int i = 0; i < numModules; ++i)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover newline

        cout << "Enter module " << (i + 1) << " name: ";
        getline(cin, moduleNames[i]);

        while (true)
        {
            cout << "Enter score for " << moduleNames[i] << ": ";
            cin >> scores[i];

            if (cin.fail())
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();                                         // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush bad input
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush rest of line
                break;                                               // Valid input; exit inner loop
            }
        }
    }

    do
    {

        cout << "\nChoose an option:\n";
        cout << "1. Know how GPA is calculated\n";
        cout << "2. Get GPA and average only \n";
        cout << "0. To exit the program \n";
        cout << "Enter choice (1 or 2): ";
        cin >> choice;

        if (choice == 1)
        {
            explainGPAConversion();
        }

        else if (choice == 2)
        {

            cout << "\n--- GPA Report ---\n";
            for (int i = 0; i < numModules; ++i)
            {
                double gpa = convertToGPA(scores[i]);
                cout << moduleNames[i] << ": " << scores[i] << " to GPA is  " << gpa << endl;
            }
            double avgGPA = calculateAverageGPA(scores);
            cout << "\nAverage GPA: " << avgGPA << endl;
        }

    } while (choice != 0);
    {
        cout << "You have exited the program! \n";
    }
    return 0;
}

double convertToGPA(double percentage)
{
    if (percentage >= 90 && percentage <= 100)
        return 4.0;
    else if (percentage >= 80 && percentage <= 89)
        return 3.7;
    else if (percentage >= 70 && percentage <= 79)
        return 3.0;
    else if (percentage >= 60 && percentage <= 69)
        return 2.0;
    else if (percentage >= 50 && percentage <= 59)
        return 1.0;
    else if (percentage >= 0 && percentage <= 49)
        return 0.0;
    else
        return 0.0;
}

// Function to calculate average GPA from a vector of scores
double calculateAverageGPA(const std::vector<double> &percentages)
{
    double totalGPA = 0;
    for (double score : percentages)
    {
        totalGPA += convertToGPA(score);
    }
    return percentages.empty() ? 0.0 : totalGPA / percentages.size();
}

// Function to display how GPA is calculated
void explainGPAConversion()
{
    cout << "\n--- GPA Conversion Table ---\n";
    cout << "90-100  : 4.0 GPA\n";
    cout << "80-89   : 3.7 GPA\n";
    cout << "70-79   : 3.0 GPA\n";
    cout << "60-69   : 2.0 GPA\n";
    cout << "50-59   : 1.0 GPA\n";
    cout << "< 50    : 0.0 GPA\n\n";
}