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
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(); // Obtain the size of the grid
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1; // If the start or end is blocked, return -1
        }
        queue<pair<int, pair<int, int>>> q;                   // Create a queue of pairs for BFS
        vector<vector<int>> distance(n, vector<int>(n, 1e9)); // Initialize distance matrix with a large value
        distance[0][0] = 1;                                   // Set the distance to the starting cell as 1
        q.push({1, {0, 0}});                                  // Push the starting cell with distance 1

        // Start BFS
        while (!q.empty())
        {
            int dis = q.front().first;         // Get the distance from the front of the queue
            int row = q.front().second.first;  // Get the row of the current cell
            int col = q.front().second.second; // Get the column of the current cell
            q.pop();                           // Pop the front element

            // Check if the current cell is the destination
            if (row == n - 1 && col == n - 1)
            {
                return dis; // If the destination is reached, return the distance
            }

            // Explore all possible neighbors of the current cell
            for (int delr = -1; delr <= 1; delr++)
            {
                for (int delc = -1; delc <= 1; delc++)
                {
                    int newr = row + delr; // Calculate the new row
                    int newc = col + delc; // Calculate the new column

                    // Check if the new position is within the grid and is a valid path
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && distance[newr][newc] > dis + 1)
                    {
                        distance[newr][newc] = dis + 1;  // Update the distance to the new cell
                        q.push({dis + 1, {newr, newc}}); // Push the new cell into the queue with updated distance
                    }
                }
            }
        }
        return -1; // If no path is found, return -1
    }
};

// Sample usage of the Solution class
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 1, 0}};

    // Find the shortest path in the binary matrix
    int shortestDistance = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest distance: " << shortestDistance << endl;
    return 0;
}
