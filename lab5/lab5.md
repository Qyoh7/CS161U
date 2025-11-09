<h1 align='center'>Lab 5</h1>

## Part 1

Write a program that performs a survey tally on beverages. The program should prompt for the next person until a sentinel value of –1 is entered to terminate the program then it should print the results out to a file (expected results are at the end of the sample run below).
Each person participating in the survey should choose their favorite beverage from the following list:

1. Coffee 
2. Tea 
3. Coke 
4. Orange Juice

Sample Run:
```text
Please input the favorite beverage of person #1: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
4
Please input the favorite beverage of person #2: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
1
Please input the favorite beverage of person #3: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
3
Please input the favorite beverage of person #4: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
1
Please input the favorite beverage of person #5: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
1
Please input the favorite beverage of person #6: Choose 1, 2, 3, or 4 from the above menu or -1 to 
exit the program
-1
```

```text
The total number of people surveyed is 5.
The results are as follows:
Beverage Number of Votes
********************************
Coffee          3
Tea             0
Coke           1
Orange Juice     1
```

## Solution

```cpp
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
```

## AI Feedback

Your program is functionally correct and produces the expected output. It uses a loop to repeatedly prompt the user and correctly tallies beverage votes, then writes the results to a file. The use of `ofstream` for file output and `EXIT_SUCCESS` for clean termination are both good practices.

That said, there are several areas where you could improve readability, robustness, and user experience:

1. **File handling:** It’s safer to use `ofstream bevFile("bevFile.txt");` directly, rather than assigning a temporary `ofstream` object. Also, the file should be closed explicitly before exiting.
2. **Input validation:** Currently, invalid input (like a letter) will cause `cin` to fail. You could clear and ignore invalid input to prevent infinite loops or unexpected behavior.
3. **Output formatting:** Adding spacing, headers, and consistent alignment improves the look of both console and file output.
4. **Code clarity:** Use arrays or an enum to represent beverages instead of multiple separate variables. This reduces repetition and makes future modifications easier.
5. **Minor typo:** The word “survayed” in the file output should be corrected to “surveyed.”

---

### Revised Code (Incorporating Feedback)

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>  // for setw and formatting
#include <limits>   // for input validation
using namespace std;

int main() {
    ofstream bevFile("bevFile.txt");
    if (!bevFile) {
        cerr << "Error: Could not open output file.\n";
        return 1;
    }

    int votes[4] = {0};  // 0: Coffee, 1: Tea, 2: Coke, 3: Orange Juice
    int choice;
    int person = 1;

    cout << "Beverage Survey\n";
    cout << "1. Coffee\n2. Tea\n3. Coke\n4. Orange Juice\n";

    while (true) {
        cout << "Please input the favorite beverage of person #" << person
             << ": Choose 1–4 from the menu or -1 to exit.\n";

        cin >> choice;

        if (!cin) {  // input validation
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4, or -1 to quit.\n";
            continue;
        }

        if (choice == -1)
            break;
        else if (choice >= 1 && choice <= 4)
            votes[choice - 1]++;
        else {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        person++;
    }

    int total = person - 1;

    bevFile << "The total number of people surveyed is " << total << ".\n";
    bevFile << "The results are as follows:\n";
    bevFile << left << setw(15) << "Beverage" << "Number of Votes\n";
    bevFile << "********************************\n";
    bevFile << left << setw(15) << "Coffee" << votes[0] << "\n";
    bevFile << left << setw(15) << "Tea" << votes[1] << "\n";
    bevFile << left << setw(15) << "Coke" << votes[2] << "\n";
    bevFile << left << setw(15) << "Orange Juice" << votes[3] << "\n";

    bevFile.close();

    cout << "Survey results have been written to bevFile.txt\n";
    return 0;
}
```

---

### Reflection Comment (for submission)

> The AI feedback helped me recognize a few subtle improvements I could make to my original code. It suggested better input validation to prevent invalid entries from breaking the loop, improved the look of the output file using formatting tools like `setw`, and corrected small mistakes such as the “survayed” typo. It also recommended using an array to simplify beverage counting and ensure easier expansion later. Overall, these suggestions made my program cleaner, safer, and more professional.
