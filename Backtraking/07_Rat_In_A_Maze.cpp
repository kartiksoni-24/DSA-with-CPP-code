#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<vector<bool>> &visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited.size(); j++)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }
}

void findPath(int maze[][4], int i, int j, int n, string ans, vector<vector<bool>> &visited)
{
    if (i == n - 1 && j == n - 1)
    {
        cout << ans << endl;
        return;
    }

    if (j + 1 < n && maze[i][j + 1] == 1 && !visited[i][j + 1])
    {
        visited[i][j + 1] = true;
        findPath(maze, i, j + 1, n, ans + "R", visited); // right
        visited[i][j + 1] = false;
    }
    if (i + 1 < n && maze[i + 1][j] == 1 && !visited[i + 1][j])
    {
        visited[i + 1][j] = true;
        findPath(maze, i + 1, j, n, ans + "D", visited); // down
        visited[i + 1][j] = false;
    }
    if (i - 1 >= 0 && maze[i - 1][j] == 1 && !visited[i - 1][j])
    {
        visited[i - 1][j] = true;
        findPath(maze, i - 1, j, n, ans + "U", visited); // up
        visited[i - 1][j] = false;
    }
    if (j - 1 >= 0 && maze[i][j - 1] == 1 && !visited[i][j - 1])
    {
        visited[i][j - 1] = true;
        findPath(maze, i, j - 1, n, ans + "L", visited); // left
        visited[i][j - 1] = false;
    }
}

int main()
{
    int n = 4;
    int maze[][4] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {1, 1, 0, 0},
                     {0, 1, 1, 1}};

    vector<vector<bool>> visited;

    for (int i = 0; i < n; i++)
    {
        vector<bool> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back(false);
        }
        visited.push_back(newRow);
    }

    // print(visited);
    findPath(maze, 0, 0, n, "", visited);
}