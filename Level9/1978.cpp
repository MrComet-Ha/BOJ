#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0 && n != 2)
        return false;
    for (int i = 3; i * i <= n; i+=2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        if (isPrime(k))
            ++count;
    }
    cout << count << "\n";
}