#include <iostream>
#include <vector>
using namespace std;

// 점심시간엔 학생들이 모두 한 줄로 서서 급식을 탐.
// 앞자리에 앉은 학생들이 앞에 줄을 서 먼저 점심을 먹고 뒷자리에 앉은 학생들은 뒤에 줄을 서 늦게 점심을 먹게 되니 이 문제를 해결하기 위해 방법을 냈다.
// 첫 번째 학생은 무조건 0번 번호를 받아 줄을 서고, 두번째로 선 학생은 0 또는 1을 받아 0을 뽑으면 그 자리에, 1을 뽑으면 바로 앞의 학생 앞으로 가서 줄을 섬
// 세번째 줄을 선 학생은 0, 1 ,2 중 하나를 뽑아 뽑은 번호만큼 앞으로 가서 줄을 서고... 이를 반복.
// ex) 5명의 학생이 줄을 서고 첫번째로 줄을 선 학생부터 다섯번째로 줄을 선 학생까지 차례대로 0, 1, 1, 3, 2 를 뽑았다고 하면,
// 1~5번까지의 순서:
// 1번 학생 : 0 -> 1
// 2번 학생 : 1 -> 2,1
// 3번 학생 : 1 -> 2,3,1
// 4번 학생 : 3 -> 4,2,3,1
// 5번 학생 : 2 - > 4,2,5,3,1
// 이를 구현하라.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cin >> m;
            if (m <= i)
                break;
        }
        vec.insert(vec.end() - m, i+1 );
    }
    for (auto i : vec)
        cout << i << " ";
}
