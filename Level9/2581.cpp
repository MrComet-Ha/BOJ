#include <iostream>
#include <climits>

using namespace std;

bool isPrime(const int& i)
{
    if (i < 2)
        return false;
    if (i % 2 == 0 && i != 2)
        return false;
    for (int j = 3; j * j <= i; j += 2)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, m, min = INT_MAX, result = 0;
    cin >> n >> m;
    for (int i = n; i <= m; ++i)
    {
        if (isPrime(i))
        {
            result += i;
            if (min > i)
                min = i;
        }
    }
    if (result == 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << result << "\n" << min << "\n";
}