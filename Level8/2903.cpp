#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long result = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        result *= 2;
    result += 1;
    result *= result;
    cout << result << "\n";
}