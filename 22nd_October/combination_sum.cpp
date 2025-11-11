#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans, int index) {
    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) continue; // prune
        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], current, ans, i); // i → can reuse
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    backtrack(candidates, target, current, ans, 0);
    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> res = combinationSum(candidates, target);
    cout << "Combination Sum results:\n";
    for (auto& comb : res) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
}