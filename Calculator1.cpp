/*This is a calculator that perform trig and arithetic calculations
It uses function inorder to perform the calculaion and these are callled in the switch statement
The user is first shown the operations that the calculator can perform then once the use select theoperation then
the calculator will call the function that is meant for that and display the result*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// functional prototypes

double addition(double, double);
double subtraction(double, double);
double multiplictaion(double, double);
double division(double, double);
double sine(double);
double cosine(double);
double tangent(double);
int main()
{

    // declaring the variables
    double num1, num2, angle, result = 0.0;
    int choice = 0;

    string prompt1 = "Select the operation you would like to perform";

    // using a while loop to makesure that the user can perform operations multiple times

    do
    {
        // Displaying the operations that the calculator will perform
        std::cout << "Welcome to my calculator in c++ \n";
        std::cout << prompt1 << endl;
        std::cout << "1. Addition \n"
                  << "2. Subtraction \n"
                  << "3. Multiplication \n"
                  << "4. Division \n"
                  << "5. Sine \n"
                  << "6. Cosine \n"
                  << "7. Tangent \n"
                  << "0. to Extit \n";

        // prompting the user for the choice of operation
        std::cout << "Enter the choice of the number of the operation you would like to perform \n";
        cin >> choice;

        // using a switch statement to select the operation that the user wants to perform
        switch (choice)
        {
        case 1:
            std::cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = addition(num1, num2);
            std::cout << "Result: " << result << endl;
            break;

        case 2:
            std::cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = subtraction(num1, num2);
            std::cout << "Result: " << result << endl;
            break;

        case 3:
            std::cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = multiplictaion(num1, num2);
            std::cout << "Result: " << result << endl;
            break;

        case 4:
            std::cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 == 0)
                std::cout << "Error: Division by zero!\n";
            else
            {
                result = division(num1, num2);
                std::cout << "Result: " << result << endl;
            }
            break;

        case 5:
            std::cout << "Enter angle in degrees: ";
            cin >> angle;
            result = sine(angle);
            std::cout << "sin(" << angle << ") = " << setprecision(4) << result << endl;
            break;

        case 6:
            std::cout << "Enter angle in degrees: ";
            cin >> angle;
            result = cosine(angle);
            std::cout << "cos(" << angle << ") = " << setprecision(4) << result << endl;
            break;

        case 7:
            std::cout << "Enter angle in degrees: ";
            cin >> angle;
            result = tangent(angle);
            std::cout << "tan(" << angle << ") = " << setprecision(4) << result << endl;
            break;

        case 0:
            std::cout << "Exited calculator.\n";
            break;

        default:
            std::cout << "Invalid choice! Enter numbers between 0 and 8.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

// function definitions
// Addition function
double addition(double num1, double num2)
{
    double sum = 0.0;
    sum = num1 + num2;
    return sum;
}

// subtraction function
double subtraction(double num1, double num2)
{
    double sum = 0.0;
    sum = num1 - num2;
    return sum;
}

// multiplication function
double multiplictaion(double num1, double num2)
{
    double sum = 0.0;
    sum = num1 * num2;
    return sum;
}

// division function
double division(double num1, double num2)
{
    double sum = 0.0;

    if (num2 != 0)
    {
        sum = num1 / num2;
    }

    else
        std::cout << "error! Division by zero!";
    return sum;
}

// sine function
double sine(double angle)
{
    const double M_PI = 3.14159265359;
    double angle_radians = angle * (M_PI / 180.0);
    double sine = sin(angle_radians);
    return sine;
}

// cosine function
double cosine(double angle)
{
    const double M_PI = 3.14159265359;
    double angle_radians = angle * (M_PI / 180.0);
    double cosine = cos(angle_radians);
    return cosine;
}

// tangent function
double tangent(double angle)
{
    const double M_PI = 3.14159265359;
    double angle_radians = angle * (M_PI / 180.0);
    double tangent = tan(angle_radians);
    return tangent;
}