#include <iostream>
#include <ostream>


int main()
{
    int age;

    std::cout << "enter your age" << std::endl;
    std::cin >> age;

    int leapYears = age / 4;
    
    int ageInDays = (age * 365) + leapYears;

    std::cout << ageInDays;
    return 0;
}
