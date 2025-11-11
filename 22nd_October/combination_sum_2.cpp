#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
        if (candidates[i] > target) break; // prune

        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, current, ans); // i+1 → no reuse
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, current, ans);
    return ans;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> res = combinationSum2(candidates, target);
    cout << "Combination Sum II results:\n";
    for (auto& comb : res) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
}
