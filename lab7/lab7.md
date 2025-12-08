<h1 align='center'>Lab 7</h1>

# My solution

```cpp
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
```
# AI Feedback

### **✔️ What You Did Well**

* Clear separation of tasks using functions.
* Good use of `vector<int>` instead of raw arrays.
* Menu loop logic is correct.
* Passing the array **by reference** for reversing is solid.

---

## ⚠️ **Issues & Suggested Improvements**

### **1. Use `const vector<int>&` for read-only functions**

Right now functions like:

```cpp
void printArray(vector<int> arr)
```

take the whole vector **by value**, meaning the entire array is copied each time — wasteful.

Use:

```cpp
void printArray(const vector<int>& arr)
```

Same for `findMinMax` and `findAverage`.

---

### **2. `rand()` generates huge values**

If you want more readable data, use a range:

```cpp
arr[i] = rand() % 100;  // 0–99
```

---

### **3. Missing `#include <ctime>` and `srand()`**

Without seeding, you get the same “random” numbers every run.

Add at top of `main()`:

```cpp
srand(time(nullptr));
```

---

### **4. Reversing array can be simpler**

Your version works, but C++ has this built in:

```cpp
reverse(arr.begin(), arr.end());
```

Since your assignment wants you to *write the function*, your implementation is fine — but you can simplify:

```cpp
void reverseArray(vector<int>& arr) {
    for (int i = 0, j = arr.size() - 1; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}
```

This avoids allocating a second vector.

---

### **5. Minor spelling fix**

Output says “Choose an option”, but could be more descriptive.

---

### **6. Minor formatting improvements**

Printing the array in a single line or with commas can improve readability:

```cpp
for (int v : arr) cout << v << " ";
cout << "\n";
```

---

## ⭐ **Polished Version (Minimal Fixes)**

Here is your program with **cleanups but NOT changing your logic**:

```cpp
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void printArray(const vector<int>& arr)
{
    for (int v : arr) {
        cout << v << "\n";
    }
}

void findMinMax(const vector<int>& arr)
{
    int min = arr.at(0);
    int max = arr.at(0);

    for (int v : arr) {
        if (v > max) max = v;
        if (v < min) min = v;
    }

    cout << "Max: " << max << "\n";
    cout << "Min: " << min << "\n";
}

void findAverage(const vector<int>& arr)
{
    double sum = 0;
    for (int v : arr) sum += v;

    cout << "Average value: " << sum / arr.size() << "\n";
}

void reverseArray(vector<int>& arr)
{
    vector<int> reversed;
    for (int i = arr.size() - 1; i >= 0; i--)
        reversed.push_back(arr.at(i));

    arr = reversed;

    cout << "Reversed array:\n";
    printArray(arr);
}

int main()
{
    srand(time(nullptr)); // seed RNG

    int ARRAY_SIZE = 10;
    vector<int> arr(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;  // readable random values

    int menuChoice;

    do {
        cout << "Choose an option\n"
             << "1. Display array\n"
             << "2. Find Maximum and Minimum Values\n"
             << "3. Calculate Average\n"
             << "4. Reverse the Array\n"
             << "5. Quit\n";

        cin >> menuChoice;
        cout << "\n";

        switch (menuChoice)
        {
            case 1: printArray(arr); break;
            case 2: findMinMax(arr); break;
            case 3: findAverage(arr); break;
            case 4: reverseArray(arr); break;
            case 5: break;
            default: cout << "Invalid menu choice\n"; break;
        }

        cout << "\n";
    } while (menuChoice != 5);
}
```

---

If you want, I can also:

🔹 Add colorized menu
🔹 Convert to functions with return values
🔹 Improve formatting
🔹 Use std::ranges (C++20)

Just ask!
