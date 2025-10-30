#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, result;
    vector<int> vec;
    while(true)
    {
        cin >> n;
        if (n == -1)
            break;
        result = 0;
        for (int i = 1; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                result += i;
                vec.push_back(i);
            }
            if (result > n)
                break;
        }
        if (result != n)
            cout << n << " is NOT perfect.";
        else
        {
            cout << n << " = ";
            for (int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i];
                if( i < vec.size()-1)
                    cout << " + ";
            }
        }
        cout << "\n";
        vec.clear();
    }
}