#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, result = 0;
	string s;
	bool isGroup, checker[26];
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		isGroup = true;
		fill(checker, checker + 26, false);
		checker[s[0] - 'a'] = true;
		for (int j = 1; j < s.length(); ++j)
		{
			if (s[j] == s[j - 1])
				continue;
			if (checker[s[j] - 'a'])
			{
				isGroup = false;
				break;
			}
			checker[s[j]-'a'] = true;
		}
		if (isGroup)
			++result;
	}
	cout << result;
}