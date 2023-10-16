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

//Leetcode
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(); // Get the number of rows in the matrix
        int m = mat[0].size(); // Get the number of columns in the matrix
        
        // Create a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Create a 2D vector to store distances
        vector<vector<int>> distance(n, vector<int>(m, 0));
        
        // Create a queue to perform BFS traversal
        queue<pair<pair<int, int>, int>> q;
        
        // Initialize the queue with cells containing '0', mark them as visited and enqueue them
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i, j}, 0}); // Enqueue cell coordinates and distance (initialized as 0)
                }
            }
        }
        
        // Perform BFS traversal
        while (!q.empty())
        {
            int r = q.front().first.first; // Get the row of the current cell
            int c = q.front().first.second; // Get the column of the current cell
            int step = q.front().second; // Get the distance from the nearest '0'
            distance[r][c] = step; // Store the distance in the result matrix
            q.pop(); // Dequeue the current cell
            
            int delrow[] = {-1, 0, 1, 0}; // Arrays to define row movement in 4 directions
            int delcol[] = {0, 1, 0, -1}; // Arrays to define column movement in 4 directions
            
            // Check all 4 directions from the current cell
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i]; // Calculate the next row
                int ncol = c + delcol[i]; // Calculate the next column

                // Check if the next cell is within bounds, unvisited, and a valid cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
                {
                    visited[nrow][ncol] = true; // Mark the next cell as visited
                    q.push({{nrow, ncol}, step + 1}); // Enqueue the next cell with an increased distance
                }
            }
        }
        
        return distance; // Return the matrix containing distances from nearest '0'
    }
};
int main()
{
    return 0;
}