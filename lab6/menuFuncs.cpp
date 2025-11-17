#include "menuFuncs.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
/*
   "1) Is a number odd or even?\n"
   "2) Is a number positive or negative?\n"
   "3) How many digits are in a number?\n"
   "4) What digit is at a specific position?\n"
   "5) Display the addition table.\n"
   "6) Display the multiplication table.\n"
   "7) Exit\n\n";
   */

int getData()
{
    int num = 0;

    while (true)
    {
        cin >> num;
        if (num < -1000000 || num > 1000000)
        {
            cout << "Error; please enter a number between -1,000,000 and 1,000,000\n";
        }
        else {
            break;
        }
    }
    return num;
}
void displayMenu(int& menuChoice)
{
    cout << "1) Is a number odd or even?\n"
        << "2) Is a number positive or negative?\n"
        << "3) How many digits are in a number?\n"
        << "4) What digit is at a specific position?\n"
        << "5) Display the addition table.\n"
        << "6) Display the multiplication table.\n"
        << "7) Exit\n\n";

    cout << "Enter a menu choice: ";
    cin >> menuChoice;
}

void processMenuChoice(int menuChoice)
{
    int tmp = 0;
    switch (menuChoice) 
    {
        case 1:
            cout << "Enter a number\n";
            cin >> tmp;
            isOddEven(tmp);
            break;
        case 2:
            cout << "Enter a number\n";
            cin >> tmp;
            isPosNeg(tmp);
            break;
        case 3:
            cout << "Enter a number\n";
            cin >> tmp;
            findNumDigits(tmp);
            break;
        case 4:
            cout << "Enter a number\n";
            cin >> tmp;
            findDigitAtPosition(tmp);
            break;
        case 5:
            displayAdditionTable();
            break;
        case 6:
            displayMultiplicationTable();
            break;
        case 7:
            cout << "\nThanks for playing!\n\n";
            break;
        default:
            cout << "\nInvalid menu choice\n";
            break;


    }
}

void isOddEven(int num)
{
    if (num % 2 == 0)
    {
        cout << "Number is even\n";
    }
    else {
        cout << "Number is odd\n";
    }
}

void isPosNeg(int num)
{
    if (num < 0)
    {
        cout << "Number is negative\n";
    }
    else if (num > 0)
    {
        cout << "Number is positive\n";
    }
    else {
        cout << "Number is 0\n";
    }
}

void findNumDigits(int num)
{
    int temp = num;
    unsigned short digits = 0;

    if (temp == 0 )
        digits = 1;
    else
    {
        for ( ; temp != 0; digits++ )
            temp /= 10;
    }
    cout << "\nThere are " << digits << " digits.\n\n";

}
void findDigitAtPosition(int num)
{
    int temp = abs(num);
    unsigned short digit_position = 0, digits = 0;

    cout << "Enter the digit position: ";
    cin >> digit_position;

    for ( ; temp != 0 && digits < digit_position - 1; digits++ )
        temp /= 10;

    cout << "\nDigit at position " << digit_position << ": " << temp % 10 << "\n\n";
}
void displayAdditionTable()
{

    cout << '\n' << setw(4) << ' ';
    for ( int col = 1; col <= 12; col++ )
        cout << setw(4) << col;

    cout << '\n';

    for ( int row = 1; row <= 12; row++)
    {
        cout << setw(4) << row;

        for ( int col = 1; col <= 12; col++ )
            cout << setw(4) << row + col;

        cout << '\n';
    }
    cout << '\n';
}
void displayMultiplicationTable()
{
    cout << '\n' << setw(4) << ' ';
    for ( int col = 1; col <= 12; col++ )
        cout << setw(4) << col;

    cout << '\n';

    for ( int row = 1; row <= 12; row++)
    {
        cout << setw(4) << row;

        for ( int col = 1; col <= 12; col++ )
            cout << setw(4) << row * col;

        cout << '\n';
    }
    cout << '\n';
}
