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
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Create a queue to perform BFS traversal
        queue<pair<int, int>> q;

        // Create a 2D visited array to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Check the boundary rows (1st and last columns)
        for (int i = 0; i < n; i++)
        {
            // Check left boundary
            if (grid[i][0] == 1)
            {
                q.push({i, 0});       // Push cell coordinates to the queue
                visited[i][0] = true; // Mark cell as visited
            }

            // Check right boundary
            if (grid[i][m - 1] == 1)
            {
                q.push({i, m - 1});       // Push cell coordinates to the queue
                visited[i][m - 1] = true; // Mark cell as visited
            }
        }

        // Check the boundary columns (1st and last rows)
        for (int j = 0; j < m; j++)
        {
            // Check top boundary
            if (grid[0][j] == 1)
            {
                q.push({0, j});       // Push cell coordinates to the queue
                visited[0][j] = true; // Mark cell as visited
            }

            // Check bottom boundary
            if (grid[n - 1][j] == 1)
            {
                q.push({n - 1, j});       // Push cell coordinates to the queue
                visited[n - 1][j] = true; // Mark cell as visited
            }
        }

        // Perform BFS traversal starting from boundary cells
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Define relative row and column offsets for 4 directions
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            // Explore neighbors in 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                // Check if the neighbor is within the grid boundaries
                // and is a valid unvisited cell with value 1
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});       // Push valid neighbor to the queue
                    visited[nrow][ncol] = true; // Mark neighbor as visited
                }
            }
        }

        // Count the unvisited enclaves (regions with value 1)
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

        return count; // Return the count of unvisited enclaves
    }
};

int main()
{
    return 0;
}