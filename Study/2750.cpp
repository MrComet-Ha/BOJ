#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    sort(vec.begin(),vec.end());
    for (auto i : vec)
        cout << i << "\n";
}