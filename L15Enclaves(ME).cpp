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
class Solution
{
    // Depth-first search function to mark 'O' cells connected to the given cell as visited
    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Mark the current cell as visited
        visited[row][col] = true;

        // Array to represent possible directions (up, right, down, left)
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Explore all four possible directions from the current cell
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check if the new cell is within bounds, unvisited, and contains 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                // Recursively call dfs on the new cell
                dfs(nrow, ncol, visited, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Create a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 1: Traverse the left and right column boundaries
        for (int i = 0; i < n; i++)
        {
            // Check left column
            if (grid[i][0] == 1)
            {
                dfs(i, 0, visited, grid);
            }

            // Check right column
            if (grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, visited, grid);
            }
        }

        // Step 2: Traverse the top and bottom row boundaries
        for (int j = 0; j < m; j++)
        {
            // Check top row
            if (grid[0][j] == 1)
            {
                dfs(0, j, visited, grid);
            }

            // Check bottom row
            if (grid[n - 1][j] == 1)
            {
                dfs(n - 1, j, visited, grid);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}