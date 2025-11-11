#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            visited[x][y] == 0 && maze[x][y] == 1);
}

void solveMaze(vector<vector<int>>& maze, int n, int x, int y,
               vector<vector<int>>& visited, string path, vector<string>& ans) {
    // Base case: destination reached
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // Possible moves (D, L, R, U)
    int newX, newY;

    // Move Down
    newX = x + 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, maze))
        solveMaze(maze, n, newX, newY, visited, path + 'D', ans);

    // Move Left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, n, visited, maze))
        solveMaze(maze, n, newX, newY, visited, path + 'L', ans);

    // Move Right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, n, visited, maze))
        solveMaze(maze, n, newX, newY, visited, path + 'R', ans);

    // Move Up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, n, visited, maze))
        solveMaze(maze, n, newX, newY, visited, path + 'U', ans);

    // Backtrack: Unmark current cell
    visited[x][y] = 0;
}

vector<string> findPaths(vector<vector<int>>& maze, int n) {
    vector<string> ans;
    if (maze[0][0] == 0) return ans; // If start is blocked

    vector<vector<int>> visited(n, vector<int>(n, 0));
    solveMaze(maze, n, 0, 0, visited, "", ans);

    sort(ans.begin(), ans.end()); // Optional: sorted lexicographically
    return ans;
}

int main() {
    int n;
    cout << "Enter size of maze (n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<string> result = findPaths(maze, n);

    if (result.empty())
        cout << "No path found!\n";
    else {
        cout << "\nAll possible paths:\n";
        for (auto& p : result)
            cout << p << endl;
    }
    return 0;
}
