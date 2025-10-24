#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long n;
    int digit, temp;
    string s;
    cin >> n >> digit;
    while(n > 0)
    {
        temp = n % digit;
        if (temp <= 9)
            s.push_back(temp  + '0');
        else 
            s.push_back(temp - 10  + 'A');
        n /= digit;
    }
    reverse(s.begin(),s.end());
    cout << s << "\n";
}