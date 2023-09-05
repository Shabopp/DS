#include<iostream>
#include<vector>
using namespace std;

void powerset(vector<int>& nums, vector<vector<int>>& ans, vector<int> output, int i)
{
    if (i >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude
    powerset(nums, ans, output, i + 1);

    // Include
    output.push_back(nums[i]);
    powerset(nums, ans, output, i + 1);
}

int main()
{
    vector<int> input = {1, 2, 3}; 
    vector<vector<int>> result;
    vector<int> output;

    powerset(input, result, output, 0);

    // Print the power set
    for (const vector<int>& subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
