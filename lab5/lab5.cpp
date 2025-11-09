#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream bevFile = ofstream("bevFile.txt");
    int coffees = 0;
    int teas = 0;
    int cokes = 0;
    int ojs = 0;
    int choice = 0;

    if (!bevFile.is_open())
    {
        cout << "Invalid filename!" << endl;
        return EXIT_FAILURE;
    }
    cout << "1. Coffee 2. Tea 3. Coke 4. Orange Juice" << endl;

    int person = 1;
    while (true)
    {
        std::cout << "Please input the favorite beverage of person # " << person << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program " << endl;
        cin >> choice;

        if (choice == 1) coffees++;
        else if (choice == 2) teas++;
        else if (choice == 3) cokes++;
        else if (choice == 4) ojs++;
        else if (choice == -1) break;
        else
        {
            cout << "Invalid choice" << endl;
            // Crime time!
            person--;
        }

        person++;
    }
    
    bevFile << "The total number of people survayed is " << person - 1 << "." << endl;
    bevFile << "The results are as follows:" << endl;
    bevFile << "Beverage Number of Votes" << endl;
    bevFile << "********************************" << endl;
    bevFile << "Coffee           " << coffees << endl;
    bevFile << "Tea              " << teas << endl;
    bevFile << "Coke             " << cokes << endl;
    bevFile << "Orange Juice     " << ojs << endl;

    return EXIT_SUCCESS;
}
