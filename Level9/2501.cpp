#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, count = 1, result = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            ++count;
        if (count == m)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}