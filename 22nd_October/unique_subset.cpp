#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current); // Add current subset to results

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates at the same recursion level
        if (i > index && nums[i] == nums[i - 1]) continue;

        // Include nums[i] in current subset
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);

        // Backtrack: remove last element
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> subsets = subsetsWithDup(nums);

    cout << "\nAll unique subsets:\n";
    for (auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
