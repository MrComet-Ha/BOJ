#include <iostream>

using namespace std;

int main()
{
    int x,y,w,h, xLength, yLength, result;
    cin >> x >> y >> w >> h;
    xLength = x < w-x ? x : w-x;
    yLength = y < h-y ? y : h-y;
    if (xLength < yLength)
        cout << xLength << "\n";
    else
        cout << yLength << "\n";
}