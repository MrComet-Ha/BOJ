#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i = 2;
    cin >> n;
    while(true)
    {
        if(n % i == 0)
        {
            cout << i << "\n";
            n /= i;
            i = 2;
        }
        else
            ++i;
        if (n == 1)
            break;
    }
}