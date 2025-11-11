#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
    return (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0 && maze[x][y] == 1);
}

void solveMaze(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited, string path, vector<string>& ans) {
    // Base case: reached destination
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Move Down
    if (isSafe(x + 1, y, n, visited, maze))
        solveMaze(x + 1, y, n, maze, visited, path + 'D', ans);

    // Move Left
    if (isSafe(x, y - 1, n, visited, maze))
        solveMaze(x, y - 1, n, maze, visited, path + 'L', ans);

    // Move Right
    if (isSafe(x, y + 1, n, visited, maze))
        solveMaze(x, y + 1, n, maze, visited, path + 'R', ans);

    // Move Up
    if (isSafe(x - 1, y, n, visited, maze))
        solveMaze(x - 1, y, n, maze, visited, path + 'U', ans);

    // Backtrack: unmark the current cell
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>& maze, int n) {
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (maze[0][0] == 0) return ans; // Start is blocked

    solveMaze(0, 0, n, maze, visited, "", ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter size of maze (n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> paths = findPath(maze, n);

    if (paths.empty()) {
        cout << "No path found!\n";
    } else {
        cout << "Possible paths:\n";
        for (auto& p : paths) {
            cout << p << endl;
        }
    }

    return 0;
}
