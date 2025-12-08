#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << "\n";
    }
}

void findMinMax(vector<int> arr)
{
    int min = arr.at(0);
    int max = arr.at(0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr.at(i) > max) max = arr.at(i);
        if (arr.at(i) < min) min = arr.at(i);
    }
    cout << "Max: " << max << "\n";
    cout << "Min: " << min << "\n";
}

void findAverage(vector<int> arr)
{
    double sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr.at(i);
    }
    double avg = sum / arr.size();
    cout << "Average value: " << avg << "\n";
}
void reverseArray(vector<int>& arr)
{
    vector<int> reversed;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        reversed.push_back(arr.at(i));
    }
    arr = reversed;
    cout << "Reversed array: " << "\n";
    printArray(arr);
}

int main()
{
    int ARRAY_SIZE = 10;
    int menuChoice = 0;
    vector<int> arr(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr.at(i) = rand();
    }    

    do {

        cout << "Choose an option" << "\n";
        cout << "1. Display array" << "\n";
        cout << "2. Find Maximum and Minimum Values" << "\n";
        cout << "3. Calculate Average" << "\n";
        cout << "4. Reverse the Array" << "\n";
        cout << "5. Quit" << "\n";
        cin >> menuChoice;
        cout << "\n";
        switch (menuChoice)
        {
            case 1: 
                printArray(arr); 
                break;

            case 2: 
                findMinMax(arr); 
                break;
            case 3: 
                findAverage(arr); 
                break;
            case 4: 
                reverseArray(arr); 
                break;
            case 5:
                break;
            default:
                cout << "Invalid menu choice\n";
                break;
        }
        cout << "\n";
    } while (menuChoice != 5);
}
