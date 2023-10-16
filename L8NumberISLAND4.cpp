//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;

// 4 Direction -LeetCode
class Solution
{
private:
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m)
    {
        // Mark the current cell as visited and enqueue it
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});

        // Begin BFS traversal
        while (!q.empty())
        {
            // Dequeue the front element and process its neighbors
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check for neighbors one by one

            // Up
            if (r - 1 >= 0 && r - 1 < n && c >= 0 && c < m && !visited[r - 1][c] && grid[r - 1][c] == '1')
            {
                visited[r - 1][c] = true;   // Mark the neighbor as visited
                q.push({r - 1, c});         // Enqueue the neighbor
            }

            // Down
            if (r + 1 >= 0 && r + 1 < n && c >= 0 && c < m && !visited[r + 1][c] && grid[r + 1][c] == '1')
            {
                visited[r + 1][c] = true;
                q.push({r + 1, c});
            }

            // Right
            if (r >= 0 && r < n && c + 1 >= 0 && c + 1 < m && !visited[r][c + 1] && grid[r][c + 1] == '1')
            {
                visited[r][c + 1] = true;
                q.push({r, c + 1});
            }

            // Left
            if (r >= 0 && r < n && c - 1 >= 0 && c - 1 < m && !visited[r][c - 1] && grid[r][c - 1] == '1')
            {
                visited[r][c - 1] = true;
                q.push({r, c - 1});
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Create a matrix to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        // Iterate through the grid cells
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                // If the cell contains '1' and is not visited, it's the start of a new island
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    count++;                    // Increment the island count
                    bfs(row, col, visited, grid, n, m);   // Perform BFS to mark all cells in this island
                }
            }
        }
        return count;   // Return the total count of islands
    }
};

int main()
{
    return 0;
}