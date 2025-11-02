<h1 align="center"> Lab 4 </h1>

## Part 1

Write a program that uses a loop to display Pattern A below, followed by another loop that displays Pattern B

### Solution

```cpp
#include <iostream>

int main()
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
```

## Part 2

Download the Random.txt file either here or in Chapter 05 from the book materials (www.pearsonhighered.com/gaddis). This file contains a long list of random numbers. Copy the file to your system, then write a program that opens the file, reads all the numbers from the file, and calculates the following:

1. The number of numbers in the file

1. The sum of all the numbers in the file (a running total)

1. The average of all the numbers in the filea. The number of numbers in the file

## Solution
```cpp
#include <iostream>
#include <fstream>

using namespace std;


int main()
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
    cout << "Average of numbers in file: " << sum / counter << endl;

    inputFile.close();
}
```

## AI Feedback

Perfect! Let’s go through your Lab 4 code and provide detailed AI-style feedback with suggestions, then a revised version for both parts.

---

### 🧩 **Evaluation + Feedback**

#### **Part 1: Patterns A and B**

**Your code:**

```cpp
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
```

**Feedback:**

1. **Correctness:** The code correctly prints both patterns. ✅
2. **Readability:** You could improve readability by adding **comments or spacing** between patterns.
3. **Loop Ranges:** Fine as-is, but consider using `i <= 10` in the first loop to match “10 + signs” explicitly, which makes the intent clearer.
4. **Formatting:** Using `std::endl` instead of `\n` is a minor improvement (flushes output, safer in some environments).

---

#### ✅ **Rewritten Part 1**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Pattern A
    cout << "Pattern A:\n";
    for (int i = 1; i <= 10; i++) {           // 1 to 10
        for (int j = 0; j < i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    cout << endl; // Spacer between patterns

    // Pattern B
    cout << "Pattern B:\n";
    for (int i = 10; i > 0; i--) {           // 10 down to 1
        for (int j = 0; j < i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}
```

**Improvements Applied:**

* Added headers for each pattern.
* Used `endl` instead of `\n`.
* Added spacing between the two patterns for clarity.
* Changed loop to `i = 1; i <= 10` to make pattern intent clearer.

---

#### **Part 2: File Reading and Statistics**

**Your code:**

```cpp
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
cout << "Average of numbers in file: " << sum / counter << endl;

inputFile.close();
```

**Feedback:**

1. **Correctness:** Code correctly counts numbers, sums them, and calculates the average. ✅
2. **Error Checking:** There’s no check to see if the file opened successfully. If `Random.txt` is missing, the program will fail silently.
3. **Division Safety:** You divide by `counter` without checking if it’s zero. If the file is empty, this will cause a runtime error.
4. **Readability:** Adding `fixed` and `setprecision` improves output formatting for sum and average.

---

#### ✅ **Rewritten Part 2**

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile("./Random.txt");

    if (!inputFile) {  // Check if file opened successfully
        cerr << "Error: Could not open Random.txt" << endl;
        return 1;
    }

    double number;
    int counter = 0;
    double sum = 0;

    while (inputFile >> number) {
        sum += number;
        counter++;
    }

    inputFile.close();

    if (counter == 0) {  // Avoid division by zero
        cout << "The file is empty." << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Numbers in file: " << counter << endl;
        cout << "Sum of numbers: " << sum << endl;
        cout << "Average of numbers: " << sum / counter << endl;
    }

    return 0;
}
```

**Improvements Applied:**

* Added **file existence/error check**.
* Added **division-by-zero check**.
* Formatted numeric output with `fixed` and `setprecision(2)` for readability.
* Added `cerr` for error messages.

---

#### 🧠 **Reflection Summary (for submission comment)**

> In Part 1, the AI suggested adding headers and spacing between patterns, as well as improving loop clarity by explicitly counting from 1 to 10. This made the patterns easier to read and understand.
> In Part 2, the AI pointed out the lack of error handling when opening files and the potential division by zero if the file is empty. It also suggested formatting numeric output for better readability. Implementing these changes made the code safer and more user-friendly.

---
