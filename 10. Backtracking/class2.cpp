#include <iostream>
#include <vector>

using namespace std;

// Check if details are available or we can proceed with currenct step
bool checkAvailable(vector<vector<int>> &maze, vector<vector<bool>> &visited, int srcx, int srcy, int n)
{
    // Check index is out of bound
    if (srcx < 0 || srcx > n || srcy < 0 || srcy > n)
    {
        return false;
    }
    // Check if the given details if not valid index
    if (maze[srcx][srcy] == 0 || visited[srcx][srcy] == true)
    {
        return false;
    }

    return true;
}

void solve(vector<vector<int>> &maze, vector<vector<bool>> &visited, int n, vector<string> &ans, int srcx, int srcy, int destx, int desty, string output)
{
    // Base case
    if (srcx == destx && srcy == desty)
    {
        ans.push_back(output);
        return;
    }

    // Check if the current source is allow then move
    // Top
    if (checkAvailable(maze, visited, srcx - 1, srcy, n))
    {
        visited[srcx - 1][srcy] = true;
        solve(maze, visited, n, ans, srcx - 1, srcy, destx, desty, output + "U");
        // Such that for other cases this visited flag do not affect
        // To revert what we have done
        visited[srcx - 1][srcy] = false;
    }

    // Bottom
    if (checkAvailable(maze, visited, srcx + 1, srcy, n))
    {
        visited[srcx + 1][srcy] = true;
        solve(maze, visited, n, ans, srcx + 1, srcy, destx, desty, output + "D");
        // Such that for other cases this visited flag do not affect
        // To revert what we have done
        visited[srcx + 1][srcy] = false;
    }

    // Left
    if (checkAvailable(maze, visited, srcx, srcy - 1, n))
    {
        visited[srcx][srcy - 1] = true;
        solve(maze, visited, n, ans, srcx, srcy - 1, destx, desty, output + "L");
        // Such that for other cases this visited flag do not affect
        // To revert what we have done
        visited[srcx][srcy - 1] = false;
    }

    // Right
    if (checkAvailable(maze, visited, srcx, srcy + 1, n))
    {
        visited[srcx][srcy + 1] = true;
        solve(maze, visited, n, ans, srcx, srcy + 1, destx, desty, output + "R");
        // Such that for other cases this visited flag do not affect
        // To revert what we have done
        visited[srcx][srcy + 1] = false;
    }
}

vector<string> findPaths(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int srcx = 0;
    int srcy = 0;
    int destx = n - 1;
    int desty = n - 1;

    string output = "";
    // specical case
    if (maze[0][0] == 0)
    {
        return ans;
    }
    visited[srcx][srcy] = true;
    solve(maze, visited, n - 1, ans, srcx, srcy, destx, desty, output);
    for (string s : ans)
    {
        cout << "ans :: " << s << endl;
    }
    return ans;
}

int main()
{
    cout << "Hellow";
    vector<vector<int>> path = {{1, 1, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 1, 1},
                                {0, 0, 1, 1}};
    // (4, vector<int>{1, 0, 0, 4});
    findPaths(path, path.size());
    return 0;
}