#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, result = 1;
    cin >> n;
    for (int i = 1; n > 1; ++i, ++result)
        n -= 6 *i;
    cout << result;
}