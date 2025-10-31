#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string temp;
    unordered_set<string> filter;
    cin >> n;
    vector<string> result;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        filter.emplace(temp);
    }
    for (auto i : filter)
        result.push_back(i);
    sort(result.begin(), result.end(), cmp);
    for (auto i : result)
        cout << i << "\n";
}