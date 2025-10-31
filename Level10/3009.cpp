#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    sort(x,x+3);
    sort(y,y+3);
    if (x[1] == x[0])
        cout << x[2];
    else
        cout << x[0];
    cout << " ";
    if (y[1] == y[0])
        cout << y[2];
    else
        cout << y[0];
}