#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    double loPercent;
    double hiPercent;
    cout << "Enter the lowest tip percentage";
    cin >> loPercent;
    cout << "Enter the highest tip percentage";
    cin >> hiPercent;

    int numPrices = 10;
    double priceStep = 10.0;
    int numPercentages = static_cast<int>(round((loPercent - hiPercent) / 5.0));
    double percentageStep = 5.0;

    vector<vector<double>> tips(numPrices, vector<double>(numPercentages));


    vector<string> prices(numPrices);
    for (int i = 0; i < numPrices; i++)
    {
        prices[i] = to_string((loPercent * i+1)) + "%";
    }
    vector<double> percentages(numPercentages);



    for (int row = 0; row < tips.size(); row++)
    {
        for (int col = 0; col < tips[row].size(); col++)
        {
            tips[row][col];
        }
    }
}
