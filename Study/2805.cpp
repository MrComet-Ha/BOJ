#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, result = 0;                   // n : 나무 개수 m : 필요한 길이 result : 최종 높이
    int max = INT_MIN;                      // max : 최대값, min : 탐색 지점
    cin >> n >> m;
    vector<int> trees(n);                   // trees(n) 초기화
    for (int i = 0; i < n; ++i)
    {
        cin >> trees[i];                    // trees 추가
        if (trees[i] > max)                 // 하면서 가장 큰 값은
            max = trees[i];                 // max 로 저장
    }
    reverse(trees.begin(),trees.end());     // 벡터를 내림차순으로 정렬
    int min = max - m;                      // 최소값 : 최대값 - 필요한 높이
    while (min <= max)                      // min, max 값을 조절해가며 탐색
    {
        int mid = min + (max - min) / 2;    // 중간값 : 최소값 + (최대값 - 최소값) / 2, 최초 탐색 지점 = 16
        long long temp = 0;                 // temp : 자른 길이의 합계
        for (auto j : trees)                // trees 의 모든 항목 j에 대해
        {
            if (j > mid)                    // j 가 mid 보다 클 경우
                temp += j - mid;            // temp 에 자른 길이 저장
        }
        if (temp >= m)                      // 값을 충족했다면
        {
            result = mid;                   // result 를 mid로 하고
            ++min;                          // min 값을 높혀 다시 시도
        }
        else                                // 값을 충족 못했다면
            --max;                          // max 값을 낮춰 다시 시도
    }
    cout << result << "\n";
}