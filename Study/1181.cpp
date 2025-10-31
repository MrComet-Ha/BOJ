#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b)
{
    if (a.size() != b.size())                   // 사이즈 다르면
        return a.size() < b.size();             // 사이즈 비교
    return a < b;                               // 같으면 문자열 비교
}
void Solution()
{
    int n;
    cin >> n;
    vector<string> result(n);                   // 결과값
    for(int i = 0; i < n; ++i)
        cin >> result[i];                       // 결과값에 저장
    sort(result.begin(),result.end(), cmp);     // 정렬
    result.erase(unique(result.begin(),result.end()),result.end()); // 중복 제거
    for(auto i : result)
        cout << i << "\n";                      // 출력
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution();
}