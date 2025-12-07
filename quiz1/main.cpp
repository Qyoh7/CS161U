#include <iomanip>
#include <iostream>
using namespace std;

struct plant
{
    double rowLength;
    double rowWidth;
    int numRows;
};

double calcArea(plant plant)
{
    return plant.rowLength * plant.rowWidth * plant.numRows;
}

int main()
{
    double availableSquareFootage = 0;
    double squareFootageUsed = 0;
    double plantArea = 0;
    int plants = 0;
    plant tmp{};

    cout << "Welcome to garden planner\n";
    cout << "\nEnter the square footage of the garden\n";
    cin >> availableSquareFootage;

    while (true)
    {

        cout << "\n\nEnter -1 at any time to stop entering plants\n";

        cout << "Enter the row width\n";
        cin >> tmp.rowWidth;
        if (tmp.rowWidth == -1) break;
        cout << "Enter the row length\n";
        cin >> tmp.rowLength;
        if (tmp.rowLength == -1) break;
        cout << "Enter the number of rows\n";
        cin >> tmp.numRows;
        if (tmp.numRows == -1) break;

        plantArea = calcArea(tmp);
        if (availableSquareFootage - plantArea < 0)
        {
            cout << "Not enough available space to fit plants! Using " << availableSquareFootage << " square feet instead\n"; // if plant does not fit, make it fit.
            squareFootageUsed += availableSquareFootage;
            availableSquareFootage = 0;
        }
        else {
            availableSquareFootage -= plantArea;
            squareFootageUsed += plantArea;
        }
        plants++;
    }
    cout << "========SUMMARY========\n";
    cout << "Total square footage used: " << squareFootageUsed << "\n";
    cout << "Number of plant types: " << plants << "\n";
    cout << "Square footage remaining: " << availableSquareFootage << "\n";
}
