# Lab 2

## Part 1

### Problem
Using the following chart, write an if/else if statement that assigns .10, .15, or .20 to commission, depending on the value in sales

| Sales | Commission Rate  |
|-------|------------------|
| Up to $10,000      | 10% |
| $10,000 to $15,000 | 15% |
| Over $15,000       | 20% |
	
### Solution

```cpp
#include <iostream>

using namespace std;

int main()
{
    double sales;
    double commission;
    cout << "Enter sales" << endl;
    cin >> sales;
    
    if (sales < 10000)
    {
        commission = sales * .1;
    }
    else if (sales <= 15000)
    {
        commission = sales * .15;
    }
    else if (sales > 15000)
    {
        commission = sales * .2;
    }
    else if (sales < 0)
    {
        cout << "Truly abysmal quarter." << endl;
        return 1;
    }
    cout << "Commission earned: " << commission << endl;
    return 0;
}
```

## Part 2

### Problem

Write nested if statements that perform the following tests: If amount1 is greater than 10 and amount2 is less than 100, display the greater of the two.

## Solution

```cpp
#include <iostream>
using namespace std;

int main()
{
    double amount1;
    double amount2;

    cout << "Enter amount1" << endl;
    cin >> amount1;

    cout << "Enter amount2" << endl;
    cin >> amount2;
    
    if (amount1 > 10.0)
    {
        if (amount2 < 100.0)
        {
            (amount1 > amount2) ? cout << amount1 : cout << amount2;
        }
    }

}
```

## Part 3

### Problem

Box Office 

A movie theater only keeps a percentage of the revenue earned from ticket sales. The remainder goes to the movie distributor. Write a program that calculates a theater’s gross and net box office profit for a night for one movie. The program should ask for the name of the movie, and how many adult and child tickets were sold. (The price of an adult ticket is $6.00 and a child’s ticket is $3.00.) Assume the theater keeps 20% of the gross box office profit.  It should display a report similar to : 
```
Movie Name:               “The Computer Takes All” 
Adult Tickets Sold:382 
Child Tickets Sold:127 
Gross Box Office Profit:    $ 2673.00 
Net Box Office Profit:    $  534.60 
Amount Paid to Distributor:    $ 2138.40 
```

Start with plans:  

plan out your inputs, outputs and processes, either using the IPO chart format I have illustrated, or the planning process illustrated in our text book. 

Write out complete pseudocode for the project. Be complete enough that another programmer could use your plans to create the project easily 

Write and test your program.


 ### Pseudocode

 ```pseudo
 SET name TO input "Enter movie name: "
 SET childTickets TO input "Enter number of child tickets sold: "
 SET adultTickets TO input "Enter number of adult tickets sold: "
 SET grossProfit TO (childTickets * 3) + (adultTickets * 6)
 SET netProfit TO grossProfit * .2
 DISPLAY "Gross box office profit: $" + grossProfit
 DISPLAY "Net box office profit: $" + netProfit
 DISPLAY "Amount paid to Distributor: $" + (grossProfit - netProfit)
 SEND name TO shadowrealm
 ```

### C++

```cpp
#include <iostream>

using namespace std;

int main()
{
    string name;
    int adultTickets;
    int childTickets;

    cout << "Enter movie name" << endl;
    getline(cin, name);
    cout << "Enter # of child tickets sold" << endl;
    cin >> childTickets;
    cout << "Enter # of adult tickets sold" << endl;
    cin >> adultTickets;

    double grossProfit = (childTickets * 3) + (adultTickets * 6);
    double netProfit = grossProfit * .2;
    cout << "Gross box office profit: $" << grossProfit << endl;
    cout << "Net box office profit: $" << netProfit << endl;
    cout << "Amount paid to distributor: $" << (grossProfit - netProfit);

    name = "";
    return 0;
}
```

## AI Feedback
Perfect — you’ve given me everything I need.
Let’s follow your lab’s exact directions step by step.

---

#### **Evaluation + Feedback**

##### **Part 1: Commission Program**

**Your code:**

```cpp
if (sales < 10000)
{
    commission = sales * .1;
}
else if (sales <= 15000)
{
    commission = sales * .15;
}
else if (sales > 15000)
{
    commission = sales * .2;
}
else if (sales < 0)
{
    cout << "Truly abysmal quarter." << endl;
    return 1;
}
```

**Feedback:**

* The negative sales check (`sales < 0`) should be the **first** condition. As written, it will **never execute**, since the earlier conditions already catch smaller numbers.
* Your output message is fine but consider making it clearer for the user.
* You don’t need `else if (sales > 15000)` — just `else` works, since all other conditions are already covered.
* Good use of `double` and structure overall.

---

##### **Revised Code (with feedback applied)**

```cpp
#include <iostream>
using namespace std;

int main()
{
    double sales, commission;

    cout << "Enter sales: ";
    cin >> sales;

    if (sales < 0)
    {
        cout << "Invalid input: Sales cannot be negative." << endl;
        return 1;
    }
    else if (sales <= 10000)
    {
        commission = sales * 0.10;
    }
    else if (sales <= 15000)
    {
        commission = sales * 0.15;
    }
    else
    {
        commission = sales * 0.20;
    }

    cout << "Commission earned: $" << commission << endl;
    return 0;
}
```

---

##### **Part 2: Nested If Statements**

**Your code:**

```cpp
if (amount1 > 10.0)
{
    if (amount2 < 100.0)
    {
        (amount1 > amount2) ? cout << amount1 : cout << amount2;
    }
}
```

**Feedback:**

* This works, but the ternary operator is less readable inside nested `if`s.
* No message is printed if conditions fail; you might want to indicate that.
* Good variable naming and logic overall.

---

##### **Revised Code**

```cpp
#include <iostream>
using namespace std;

int main()
{
    double amount1, amount2;

    cout << "Enter amount1: ";
    cin >> amount1;

    cout << "Enter amount2: ";
    cin >> amount2;

    if (amount1 > 10.0)
    {
        if (amount2 < 100.0)
        {
            if (amount1 > amount2)
                cout << "The greater amount is: " << amount1 << endl;
            else
                cout << "The greater amount is: " << amount2 << endl;
        }
        else
        {
            cout << "amount2 is not less than 100." << endl;
        }
    }
    else
    {
        cout << "amount1 is not greater than 10." << endl;
    }

    return 0;
}
```

---

##### **Part 3: Box Office Program**

**Your code:**

```cpp
double grossProfit = (childTickets * 3) + (adultTickets * 6);
double netProfit = grossProfit * .2;
cout << "Gross box office profit: $" << grossProfit << endl;
cout << "Net box office profit: $" << netProfit << endl;
cout << "Amount paid to distributor: $" << (grossProfit - netProfit);
```

**Feedback:**

* The math is correct! 
* You should format money values to **two decimal places** for readability.
* You might want to **display the movie name** in your final output (like the example).
* You can remove the `name = "";` line — it serves no purpose.
* `getline(cin, name)` after `cin` inputs can fail due to leftover newline characters; better to handle input order carefully or clear the buffer.

---

##### **Revised Code**

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string name;
    int adultTickets, childTickets;

    cout << "Enter movie name: ";
    getline(cin, name);

    cout << "Enter # of adult tickets sold: ";
    cin >> adultTickets;

    cout << "Enter # of child tickets sold: ";
    cin >> childTickets;

    double grossProfit = (adultTickets * 6.0) + (childTickets * 3.0);
    double netProfit = grossProfit * 0.20;
    double distributorPayment = grossProfit - netProfit;

    cout << fixed << setprecision(2);
    cout << "\nMovie Name: " << name << endl;
    cout << "Adult Tickets Sold: " << adultTickets << endl;
    cout << "Child Tickets Sold: " << childTickets << endl;
    cout << "Gross Box Office Profit: $" << grossProfit << endl;
    cout << "Net Box Office Profit: $" << netProfit << endl;
    cout << "Amount Paid to Distributor: $" << distributorPayment << endl;

    return 0;
}
```

---

#### Reflection Summary (for your submission comment)

> The AI feedback helped me fix logical and structural issues.
> For Part 1, it pointed out that my negative sales check would never run because of the order of conditions, and it simplified the structure.
> For Part 2, it made my nested `if`s more readable and added output for failing conditions.
> For Part 3, it suggested formatting my money outputs with two decimals and including the movie name in the final report for clarity.
> Overall, the feedback made my programs more user-friendly and readable.

---
