#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[j]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3}; // Replace with your input numbers
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);

    // Printing the permutations
    for (const auto& perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
