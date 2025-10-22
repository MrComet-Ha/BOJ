#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Subject
{
	string name;
	float score;
	string rank;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double result = 0, total = 0;
	map<string, float> ranking;
	ranking.emplace(pair<string, float>("A+", 4.5f));
	ranking.emplace(pair<string, float>("A0", 4.0f));
	ranking.emplace(pair<string, float>("B+", 3.5f));
	ranking.emplace(pair<string, float>("B0", 3.0f));
	ranking.emplace(pair<string, float>("C+", 2.5f));
	ranking.emplace(pair<string, float>("C0", 2.0f));
	ranking.emplace(pair<string, float>("D+", 1.5f));
	ranking.emplace(pair<string, float>("D0", 1.0f));
	ranking.emplace(pair<string, float>("F", 0));
	for (int i = 0; i < 20; i++)
	{
		Subject subject;
		cin >> subject.name >> subject.score >> subject.rank;
		if (subject.rank != "P")
		{
			result += subject.score * ranking[subject.rank];
			total += subject.score;
		}
	}
	if (result != 0)
		result /= total;
	cout.precision(6);
	cout << fixed << result;
}