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
//GFG
class Solution
{
public:
    // Function to find the shortest path between source and destination in a grid
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // Retrieving the number of rows and columns in the grid
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Creating a 2D vector to store distances initialized to a large value
        vector<vector<int>> distance(n, vector<int>(m, 1e9));

        // Initializing the distance of the source cell as 0
        distance[source.first][source.second] = 0;

        // Creating a queue to perform breadth-first search
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}}); // Pushing the source cell with distance 0

        // Loop until the queue is not empty
        while (!q.empty())
        {
            // Extract the front element's distance, row, and column
            int dis = q.front().first;         // Distance of the current cell from the source
            int row = q.front().second.first;  // Row index of the current cell
            int col = q.front().second.second; // Column index of the current cell
            q.pop();                           // Remove the front element from the queue

            // Check if the current cell is the destination cell
            if (row == destination.first && col == destination.second)
            {
                return dis; // Return the distance if the destination is reached
            }

            // Define the possible movements: up, right, down, left
            int delr[] = {-1, 0, 1, 0}; // Change in row for each direction
            int delc[] = {0, 1, 0, -1}; // Change in column for each direction

            // Iterate through all possible movements
            for (int i = 0; i < 4; i++)
            {
                // Calculate the new row and column based on the current movement
                int newr = row + delr[i]; // New row index
                int newc = col + delc[i]; // New column index

                // Check if the new position is within the grid and is a valid path (grid[newr][newc] == 1)
                // Also, check if the new path results in a shorter distance
                if ((newr >= 0) && (newr < n) && (newc >= 0) && (newc < m) && (grid[newr][newc] == 1) && (distance[newr][newc] > dis + 1))
                {
                    // Update the distance for the new cell
                    distance[newr][newc] = dis + 1;

                    // If the new cell is the destination cell, return its distance
                    if (newr == destination.first && newc == destination.second)
                    {
                        return distance[newr][newc];
                    }

                    // Push the new cell into the queue with the updated distance
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }
        // If the destination is not reachable, return -1
        return -1;
    }
};

// Sample usage of the Solution class
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 1, 0, 1},
                                {1, 0, 1, 1},
                                {1, 1, 1, 1},
                                {0, 0, 1, 1}};
    pair<int, int> source = {0, 0};      // Source cell coordinates
    pair<int, int> destination = {3, 2}; // Destination cell coordinates

    // Find the shortest path between the source and destination in the grid
    int shortestDistance = sol.shortestPath(grid, source, destination);
    cout << "Shortest distance: " << shortestDistance << endl;
    return 0;
}

