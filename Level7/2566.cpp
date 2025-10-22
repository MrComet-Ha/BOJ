#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int max = INT_MIN;
	pair<int, int> location;
	vector<vector<int>> vec(9, vector<int>(9));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> vec[i][j];
			if (vec[i][j] > max)
			{
				max = vec[i][j];
				location = make_pair(i + 1, j + 1);
			}
		}
	}
	cout << max << "\n" << location.first << " " << location.second << "\n";
}