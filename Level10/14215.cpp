#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t[3];
    int temp = 0, max, result = 0;
    for (int i = 0; i < 3; ++i)
    {    
        cin >> t[i];
        temp += t[i];
    }
    max = *max_element(t,t+3);
    if (max >= temp - max)
    {
        temp -= max;
        result = temp + (temp - 1);
    }
    else
        result = temp;
    cout << result;
}