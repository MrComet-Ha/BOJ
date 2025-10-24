#include <iostream>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int result = 0, count = 0;          // result : 결과값, count : 현재 누적된 파이프 수
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')                 // ( 라면 (쇠막대 시작 or 레이저 시작)
            ++count;                    // 파이프 수 증가
        else                            // ) 라면
        {
            --count;                    // 누적된 파이프 수 감소
            if(s[i-1] == '(')           // 이전에 나온게 ( 라면 레이저이기 때문에
                result += count;        // 현재 누적된 파이프 수를 그대로 추가
            else                        // 이전에 나온게 ) 라면 파이프의 끝이기 때문에
                ++result;               // 1만 증가
        }
    }
    cout << result << "\n";
}