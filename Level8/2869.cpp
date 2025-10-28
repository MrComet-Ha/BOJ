#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, l, day;
    cin >> n >> m >> l;
    day = ceil((double)(l-n) / (n-m));
    cout << day << "\n";
}