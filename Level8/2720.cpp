#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int coins[] = {25, 10, 5, 1};
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 0; j < 4; ++j)
        {
            cout << m / coins[j] << " ";
            m %= coins[j];
        }
        cout << "\n";
    }
}