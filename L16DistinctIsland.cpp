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
private:
    // Depth-First Search function to explore an island
    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int row0, int col0)
    {
        // Mark the current cell as visited
        visited[row][col] = true;

        // Calculate relative coordinates and add to the 'temp' vector
        temp.push_back({(row - row0), (col - col0)});

        // Possible directions to move: up, right, down, left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Explore each direction
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check if the new cell is within bounds, unvisited, and part of the island
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                // Recursively explore the new cell
                dfs(nrow, ncol, visited, grid, temp, row0, col0);
            }
        }
    }

public:
    // Function to count distinct islands
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Create a 2D visited array to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Set to store unique island shapes
        set<vector<pair<int, int>>> st;

        // Traverse the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If an unvisited land cell is found, start exploring the island
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;          // Store the shape of the island
                    dfs(i, j, visited, grid, temp, i, j); // DFS to explore the island
                    st.insert(temp);                      // Insert the island shape into the set
                }
            }
        }

        // Return the count of distinct island shapes
        return st.size();
    }
};

int main()
{
    return 0;
}