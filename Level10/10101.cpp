#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string result;
    int nums[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> nums[i];
    }
    if (nums[0] + nums[1] + nums[2] != 180)
        result = "Error";
    else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
    {
        if (nums[0] == nums[1] && nums[1] == nums[2])
            result = "Equilateral";
        else 
            result = "Isosceles";
    }
    else
        result = "Scalene";
    cout << result << "\n";
}