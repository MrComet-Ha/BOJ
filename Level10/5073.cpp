#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t[3];
    int temp, max;
    string result;
    while(true)
    {
        temp = 0;
        for(int i = 0; i < 3; ++i)
        {
            cin >> t[i];
            temp += t[i];
        }
        if (t[0] == 0 && t[1] == 0 && t[2] == 0)
            break;
        max = *max_element(t,t + 3);
        if (max >= temp - max)
            result = "Invalid";
        else if (t[0] == t[1] || t[1] == t[2] || t[0] == t[2])
        {
            if (t[0] == t[1] && t[1] == t[2])
                result = "Equilateral";
            else
                result = "Isosceles";
        }
        else
            result = "Scalene";
        cout << result << "\n";
    }   
}