#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> answerKey{'a', 'd', 'b', 'b', 'c', 'b', 'a', 'b', 'c', 'd', 'a', 'c', 'd', 'b', 'd', 'c', 'c', 'a', 'd', 'b'};
    vector<char> userAnswers;
    vector<int> incorrectAnswers;
    char ans; 
    int incorrect = 0;
    
    for (int i = 0; i < answerKey.size(); i++)
    {
        cout << "Enter answer for #" << i + 1 << '\n';
        cin >> ans;
        ans = tolower(ans);
        if (ans == 'a' || ans == 'b' || ans == 'c' || ans == 'd')
        {
            userAnswers.push_back(tolower(ans));
        }
        else 
        {
            cout << "Invalid answer. Please enter A, B, C, or D\n";
            cout << ans << "\n";
            i--;
        }
    }
    for (int i = 0; i < userAnswers.size(); i++)
    {
        if (userAnswers.at(i) != answerKey.at(i))
        {
            incorrect++;
            incorrectAnswers.push_back(i);
        }
    }
    cout << "Score: " << answerKey.size() - incorrect << " / " << answerKey.size() << "\n";
    if (incorrect <= 5)
    {
        cout << "Student passed\n";
    }
    else
    {
        cout << "Student failed\n";
    }

    if (incorrect != 0)
    {
        cout << "Incorrect Answers: \n";
        for (int ans : incorrectAnswers)
        {
            cout << ans << "\n";
        }
    }
}
