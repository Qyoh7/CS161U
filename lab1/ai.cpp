#include <iostream>

int main() {
    // Declare variables
    int age;
    const int DAYS_IN_YEAR = 365;

    // Input
    std::cout << "Enter your age in years: ";
    std::cin >> age;

    // Optional: basic input validation
    if (age < 0) {
        std::cout << "Age cannot be negative!" << std::endl;
        return 1;
    }

    // Calculation
    int leapYears = age / 4; // approximate leap years
    int ageInDays = (age * DAYS_IN_YEAR) + leapYears;

    // Output
    std::cout << "You are approximately " << ageInDays << " days old." << std::endl;

    return 0;
}
