#include <iostream>
#include <string>
#include <iomanip>
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
