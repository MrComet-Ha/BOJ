#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> vec(5);
	int maxSize = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> vec[i];
		if (vec[i].size() > maxSize)
			maxSize = vec[i].size();
	}
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < vec[j].size())
				cout << vec[j][i];
		}
	}
}