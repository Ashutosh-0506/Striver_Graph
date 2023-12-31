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
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // Getting the number of rows and columns in the given matrix
        int n = heights.size();    // Number of rows
        int m = heights[0].size(); // Number of columns

        // Initializing a priority queue that stores pairs of integers and pairs of integers with minimum value at the top
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Initializing a 2D vector 'distance' with a large value for each cell
        vector<vector<int>> distance(n, vector<int>(m, 1e9));

        // Setting the distance of the starting cell to 0
        distance[0][0] = 0;

        // Adding the starting cell (0,0) to the priority queue with distance 0
        pq.push({0, {0, 0}});

        // Loop until the priority queue is not empty
        while (!pq.empty())
        {
            // Extracting the top element from the priority queue
            auto it = pq.top();
            int dis = it.first;         // The current distance
            int row = it.second.first;  // The current row
            int col = it.second.second; // The current column
            pq.pop();

            // Checking if the current cell is the destination cell (bottom-right corner)
            if (row == n - 1 && col == m - 1)
            {
                // If the current cell is the destination, return the current distance
                return dis;
            }

            // Defining the possible directions: up, right, down, left
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            // Looping through all possible directions
            for (int i = 0; i < 4; i++)
            {
                // Calculating the new row and column based on the current direction
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking if the new row and column are within the matrix boundaries
                if (newr >= 0 && newr < n && newc >= 0 && newc < m)
                {
                    // Calculating the new effort as the maximum between the current distance and the absolute difference between the heights of the current and new cells
                    int neweffort = max(dis, abs(heights[newr][newc] - heights[row][col]));

                    // Checking if the new effort is less than the current distance in the 'distance' matrix
                    if (neweffort < distance[newr][newc])
                    {
                        // Updating the distance to the new effort if it is less and pushing the new cell to the priority queue
                        distance[newr][newc] = neweffort;
                        pq.push({neweffort, {newr, newc}});
                    }
                }
            }
        }
        // Returning 0 if the destination cell is not reachable
        return 0;
    }
};

int main()
{
    return 0;
}