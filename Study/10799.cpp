#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int result = 0, count = 0;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')
            ++count;
        else
        {
            --count;
            if(s[i-1] == '(')
                result += count;
            else
                ++result;
        }
    }
    cout << result << "\n";
}