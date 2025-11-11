#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& ans) {
    if (current.size() == k) {
        ans.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        backtrack(n, k, i + 1, current, ans);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> current;
    backtrack(n, k, 1, current, ans);
    return ans;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> res = combine(n, k);

    cout << "Combinations:\n";
    for (auto& comb : res) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
}
code