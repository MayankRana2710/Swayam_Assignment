#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);        // Swap current index with i
        permute(str, l + 1, r);      // Recurse
        swap(str[l], str[i]);        // Backtrack
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "All permutations:\n";
    permute(s, 0, s.size() - 1);
    return 0;
}
