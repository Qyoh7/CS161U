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

    name = "";
    return 0;
}
