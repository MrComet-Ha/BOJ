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
    vector<int> vec(n+m);               // vec을 n+m으로 capacity 지정
    for (int i = 0; i < n; ++i)
        cin >> vec[i];                  // vec의 0~n-1까지 총 n개 채움
    for(int i = n; i < n + m; ++i)
        cin >> vec[i];                  // n~m-1 까지 총 m개 채움
    sort(vec.begin(),vec.end());        // 정렬
    for(auto i : vec)
        cout << i << " ";               // 출력
}