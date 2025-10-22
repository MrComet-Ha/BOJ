#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<bool>> vec(100, vector<bool>(100));
	int n, temp1, temp2, result = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp1 >> temp2;
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				if (!vec[temp1 - 1 + j][temp2 - 1 + k])
				{
					vec[temp1 - 1 + j][temp2 - 1 + k] = true;
					++result;
				}
			}
		}
	}
	cout << result;
}