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
    // Depth-first search function to perform flood fill
    void dfs(int n, int m, vector<vector<int>> &image, vector<vector<bool>> &visited, int row, int col, int oldcolor, int newcolor)
    {
        // Mark the current cell as visited and update its color
        visited[row][col] = true;
        image[row][col] = newcolor;

        // Define offsets for moving in 4 directions: up, right, down, left
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // Explore all 4 directions from the current cell
        for (int i = 0; i < 4; i++)
        {
            // Calculate the new row and column indices for the next cell
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            // Check if the new indices are within bounds and the cell is unvisited and has the old color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && image[nrow][ncol] == oldcolor)
            {
                // Recursively call dfs to continue the flood fill from the new cell
                dfs(n, m, image, visited, nrow, ncol, oldcolor, newcolor);
            }
        }
    }

public:
    // Function to initiate the flood fill
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();

        // Create a 2D array to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Store the original color of the starting cell and the new color for flood fill
        int oldcolor = image[sr][sc];
        int newcolor = color;

        // Call the dfs function to start the flood fill process
        dfs(n, m, image, visited, sr, sc, oldcolor, newcolor);

        // Return the modified image after flood fill
        return image;
    }
};

int main()
{
    return 0;
}