#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> vec(n+m);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    for(int i = n; i < n + m; ++i)
        cin >> vec[i];
    sort(vec.begin(),vec.end());
    for(auto i : vec)
        cout << i << " ";
}