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

// For All 8 Directions -GFG
class Solution
{
private:
    // BFS traversal starting from the given row and column
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m)
    {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // Start BFS traversal
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Traverse in all 8 directions around the current cell
            for (int delr = -1; delr <= 1; delr++)
            {
                for (int delc = -1; delc <= 1; delc++)
                {
                    int nrow = delr + r;
                    int ncol = delc + c;

                    // Check if the new row and column are within valid bounds
                    // and the cell is unvisited and contains '1'
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        visited[nrow][ncol] = true;   // Mark the new cell as visited
                        q.push({nrow, ncol});         // Enqueue the new cell for further exploration
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands in the given grid
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Matrix to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        // Iterate through all cells in the grid
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