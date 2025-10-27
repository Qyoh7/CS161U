<h1 align="center"> Lab 3 </h1>

## Part 1

### Problem

 Write a program that uses a loop to display the characters for the ASCII codes 0 through 127.

### Solution

```cpp
#include <iostream>

int main()
{
    for (int i = 0; i < 127; i++)
    {
        std::cout << static_cast<char>(i) << std::endl;
    }
}
```

## Part 2

### Problem
A country club, which currently charges $2,500 per year for membership, has announced it will increase its membership fee by 4 percent each year for the next 6 years. Write a program that uses a loop to display the projected rates for the next 6 years. 

### Solution

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    double price = 2500;

    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << "Initial price: $" << price << std::endl;
    for (int i = 0; i < 6; i++)
    {
        price *= 1.04;
        std::cout << "Year " << (i + 1) << " price: $" << price << " per year"<< std::endl;
    }
}
```

## AI feedback


Great! Let’s go through your Lab 3 code step by step, provide detailed AI-style feedback, and rewrite it with improvements.

---

### 🧩 **Evaluation + Feedback**

#### **Part 1: ASCII Characters**

**Your code:**

```cpp
for (int i = 0; i < 127; i++)
{
    std::cout << static_cast<char>(i) << std::endl;
}
```

**Feedback:**

1. **Off-by-one:** The loop goes from 0 to 126, but the problem asks for 0 through 127. You should use `i <= 127`.
2. **Formatting:** Right now, it prints **one character per line**, but the instructions say **16 characters per line**. Use a counter and `\t` or spacing to align output.
3. **Readability:** Adding a header or spacing every 16 characters improves clarity.

---

#### ✅ **Rewritten Part 1**

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    for (int i = 0; i <= 127; i++)
    {
        std::cout << std::setw(3) << static_cast<char>(i) << " ";
        if ((i + 1) % 16 == 0) // 16 characters per line
            std::cout << std::endl;
    }
    return 0;
}
```

**Improvements applied:**

* Fixed range to include 127.
* Prints 16 characters per line.
* Added `setw(3)` for better alignment.

---

#### **Part 2: Country Club Membership**

**Your code:**

```cpp
double price = 2500;

std::cout << std::fixed << std::setprecision(2);

std::cout << "Initial price: $" << price << std::endl;
for (int i = 0; i < 6; i++)
{
    price *= 1.04;
    std::cout << "Year " << (i + 1) << " price: $" << price << " per year"<< std::endl;
}
```

**Feedback:**

1. **Accuracy:** Correctly calculates the 4% increase each year.
2. **Formatting:** Could format output nicely in a table, e.g., with `setw` so the years and prices align.
3. **Clarity:** Optionally, include the **final price after 6 years** summary.
4. **Readability:** Using `i + 1` for the year is fine. Could add `$` sign formatting consistency.

---

#### ✅ **Rewritten Part 2**

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    double price = 2500.0;
    const double increase = 0.04;
    const int years = 6;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Projected Country Club Membership Fees:\n";
    std::cout << "Year\tPrice\n";
    
    for (int i = 1; i <= years; i++)
    {
        price *= (1 + increase);
        std::cout << std::setw(4) << i << "\t$" << std::setw(8) << price << std::endl;
    }

    return 0;
}
```

**Improvements applied:**

* Output is now aligned in a table for readability.
* Loop starts from 1 to `years` for more natural labeling.
* Added header for clarity.
* `setw` aligns the numbers neatly.

---

#### 🧠 **Reflection Summary (for submission comment)**

> The AI feedback helped me identify logical and formatting issues in my code.
> In Part 1, it pointed out that my loop excluded ASCII 127 and didn’t display 16 characters per line, which I fixed with alignment and a line break.
> In Part 2, the AI suggested formatting the membership fees in a table with aligned columns, improving readability and clarity.
> Overall, the changes made the programs more user-friendly, structured, and visually clear.

---

If you want, I can **combine Lab 3 Part 1 and 2 into a single clean Markdown submission** with your original code, AI feedback, and rewritten versions—perfect for turning in.

Do you want me to do that?
