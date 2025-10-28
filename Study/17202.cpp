#include <iostream>

using namespace std;

int main()
{
    char num1[9];
    char num2[9];

    int arr[16];

    cin >> num1 >> num2;

    for (int i = 0; i < 8; ++i)
    {
        arr[i * 2] = num1[i] - '0';
        arr[i * 2 + 1] = num2[i] - '0';
    }

    for(int i = 14; i >= 1; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            arr[j] = (arr[j] + arr[j+1]) % 10;
        }
    }

    cout << arr[0] << arr[1] << "\n";
}