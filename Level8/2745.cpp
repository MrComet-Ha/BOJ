#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int digit, temp;
	long long result = 0;
	string s;
	cin >> s >> digit;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] <= '9')
			temp = s[i] - '0';
		else
			temp = s[i] - 'A' + 10;
		result = result * digit + temp;
	}
	cout << result;
}