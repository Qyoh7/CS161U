#include <cctype>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    vector<char> answerKey{'a', 'd', 'b', 'b', 'c', 'b', 'a', 'b', 'c', 'd', 'a', 'c', 'd', 'b', 'd', 'c', 'c', 'a', 'd', 'b'};
    vector<char> userAnswers;
    char ans; 
    int incorrect = 0;
    
    for (int i = 0; i < answerKey.size(); i++)
    {
        cout << "Enter answer for #" << i + 1 << '\n';
        cin >> ans;
        if (tolower(ans) != ('a' || 'b' || 'c' || 'd'))
        {
            cout << "Invalid answer. Please enter A, B, C, or D\n";
            i--;
        }
        else 
        {
            userAnswers.push_back(tolower(ans));
        }
    }
    for (int i = 0; i < userAnswers.size(); i++)
    {
        if (userAnswers.at(i) != ans)
    }
}
