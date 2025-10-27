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
