#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i = 1;
    cin >> n;
    for (; n > 0; ++i)
        n -= i;
    if ( i % 2 == 1 )
        cout << (i - 1) + n << " / " << 1 - n << "\n";
    else 
        cout << 1 - n << " / " << (i - 1) + n << "\n";
}