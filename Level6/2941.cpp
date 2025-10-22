#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int count = 0, i = 0, len = s.length();

	while (i < len)
	{
		++count;
		if ((i + 2 < len) && s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
			i += 3;
		else if ((i + 1 < len) && (s[i] == 'c' || s[i] == 'd') && s[i + 1] == '-')
			i += 2;
		else if ((i + 1 < len) && (s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j')
			i += 2;
		else if ((i + 1 < len) && (s[i] == 'c' || s[i] == 's' || s[i] == 'z') && s[i + 1] == '=')
			i += 2;
		else
			++i;
	}
	cout << count << "\n";
}