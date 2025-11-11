#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int index, vector<int> &arr, vector<int> &current) {
    if (index == arr.size()) {
        cout << "{ ";
        for (int num : current) cout << num << " ";
        cout << "}" << endl;
        return;
    }

    // Include current element
    current.push_back(arr[index]);
    generateSubsets(index + 1, arr, current);

    // Exclude current element
    current.pop_back();
    generateSubsets(index + 1, arr, current);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> current;
    generateSubsets(0, arr, current);
    return 0;
}
