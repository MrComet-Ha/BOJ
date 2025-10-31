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
    vector<int> vec(n);             // 값을 vector에 저장
    for (int i = 0; i < n; ++i)
        cin >> vec[i];              // vec에 값 삽입
    sort(vec.begin(),vec.end());    // 정렬
    for (auto i : vec)
        cout << i << "\n";          // 출력
}