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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        // Create a queue to perform BFS (Breadth-First Search)
        queue<pair<pair<int, int>, int>> q;
        
        // Create a 2D array to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int freshcount = 0; // Count of fresh oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2) // If an orange is rotten
                {
                    q.push({{i, j}, 0}); // Push its position and time taken to rot
                    visited[i][j] = true; // Mark the cell as visited
                }
                if (grid[i][j] == 1) // If an orange is fresh
                {
                    freshcount++; // Increment fresh orange count
                }
            }
        }
        
        int maxtime = 0; // Maximum time taken for all oranges to rot
        int freshrott = 0; // Count of fresh oranges that have rotted
        while (!q.empty())
        {
            int r = q.front().first.first; // Row of the current orange
            int c = q.front().first.second; // Column of the current orange
            int t = q.front().second; // Time taken for the current orange to rot
            q.pop();
            maxtime = max(maxtime, t); // Update the maximum time taken
            
            int delrow[] = {-1, 0, 1, 0}; // Offsets for moving in 4 directions: up, right, down, left
            int delcol[] = {0, 1, 0, -1};
            
            // Explore adjacent cells
            for (int i = 0; i < 4; i++)
            {
                int nrow = delrow[i] + r; // New row index of the adjacent cell
                int ncol = delcol[i] + c; // New column index of the adjacent cell
                
                // Check if the new indices are within bounds and the cell is unvisited and has a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1}); // Push the adjacent cell into the queue
                    visited[nrow][ncol] = true; // Mark the adjacent cell as visited
                    freshrott++; // Increment the count of fresh oranges that have rotted
                }
            }
        }
        
        // If there are still fresh oranges that haven't rotted, return -1
        if (freshcount != freshrott)
        {
            return -1;
        }
        
        return maxtime; // Return the maximum time taken for all oranges to rot
    }
};

int main()
{
    return 0;
}