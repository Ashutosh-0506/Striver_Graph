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
    // Depth-first search function to mark 'O' cells connected to the given cell as visited
    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        
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
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                // Recursively call dfs on the new cell
                dfs(nrow, ncol, visited, board);
            }
        }
    }

public:
    // Main function to solve the surrounded regions problem
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        
        // Create a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 1: Traverse the left and right column boundaries
        for (int i = 0; i < n; i++)
        {
            // Check left column
            if (board[i][0] == 'O')
            {
                dfs(i, 0, visited, board);
            }

            // Check right column
            if (board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, board);
            }
        }

        // Step 2: Traverse the top and bottom row boundaries
        for (int j = 0; j < m; j++)
        {
            // Check top row
            if (board[0][j] == 'O')
            {
                dfs(0, j, visited, board);
            }

            // Check bottom row
            if (board[n - 1][j] == 'O')
            {
                dfs(n - 1, j, visited, board);
            }
        }
        
        // Step 3: Convert remaining unvisited 'O' cells to 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    return 0;
}