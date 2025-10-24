#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <unordered_map> // 정렬 기준 없이 단순히 데이터를 저장하고 빠르게 탐색하기 위한 map


using namespace std;

// void Func2605()
// {
//     int n, num;
//     int count = 0;
//     list<int> answer;
//     list<int>::iterator itr;
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//     {
//         while (true)
//         {
//             cin >> num;
//             if (num <= i)
//                 break;
//         }
//         itr = answer.end();
//         while (num > 0)
//         {
//             itr--;
//             num--;
//         }
//         answer.insert(itr, i+1);
//     }
//     for (auto i : answer)
//         cout << i << " ";
// }

// void Func()
// {
//     string s = "()(((()())(())()))(())";
//     int result = 0;
//     stack<char> stk;
//     for (int i = 0; i < s.length(); ++i)
//     {
//         if (!stk.empty())
//         {
//             if(stk.top() == '(' && s[i] == ')')
//             {
//                 stk.pop();
//                 result += stk.size();
//             }
//             else
//                 stk.push(s[i]);
//         }
//         else
//             stk.push(s[i]);
//     }
//     cout << result << "\n";
// }

// 해쉬테이블 구현

const int TableSize = 10;
class HashTable
{
    list<pair<string, string>> table[TableSize];
    public:
    // 키 값에 따라 Hash의 Index인 HashKey를 만든다.
    int hashFunc(string key)
    {
        int hash = 0;
        for (char c : key)
            hash = (hash * 31 + c) % TableSize;
        return hash;
    }

    void insert(string key, string value)
    {
        int index = hashFunc(key);
        table[index].push_back({key,value});
    }

    string Find(string key)
    {
        int index = hashFunc(key);
        for(auto& p : table[index])
        {
            if(p.first == key)
                return p.second;
        }
        return "NotFound";
    }
};

int main()
{
    // 구현한 HashTable 실사용

    // HashTable hashT;
    // hashT.insert("cheolsu","010-1234-5678");
    // hashT.insert("yonghee","010-8765-4321");
    // hashT.insert("yongsu","010-2345-6789");
    // hashT.insert("dongcheol","010-9876-5432");
    // hashT.insert("jinsu","010-1324-5768");
    // cout << hashT.Find("dongcheol") << "\n";

    // unordered_map 실사용

    // unordered_map<string, int> uomap;
    // uomap["준식"] = 0;
    // uomap["영희"] = 50;
    // uomap["용수"] = 80;
    // uomap["도식"] = 98;
    // cout << uomap["도식"] << "\n";

    
}