#include <iostream>
#include <fstream>

using namespace std;


void readFile()
{
    ifstream inputFile = ifstream("./Random.txt");
    double number;
    int counter = 0;
    double sum = 0;

    while (inputFile >> number)
    {
        sum += number;
        counter++;
    }
    
    cout << "Numbers in file: " << counter << endl;
    cout << "Sum of numbers in file: " << sum << endl;
    cout << "Average of numbers in file: " << sum / number << endl;
    inputFile.close();
}

void part1()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "+";
        }

        std::cout << "\n";
    }

    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "+";
        }

        std::cout << "\n";
    }
}

int main()
{
    readFile();
}
