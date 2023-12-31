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

// C++ code implements the Floyd-Warshall algorithm to find the shortest distances between all pairs 
//of vertices in a graph represented by an adjacency matrix. 
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size(); // Get the number of vertices in the graph

        // Step 1: Initialize the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0; // Diagonal elements represent the distance to itself (0 distance)
                }
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9; // If there is no direct edge, set the distance to a large value (infinity)
                }
            }
        }

        // Step 2: Apply the Floyd-Warshall algorithm
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // Update the distance matrix by considering vertex k as an intermediate vertex
                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
                }
            }
        }

        // Step 3: Convert back the large values to -1 for vertices that are not directly connected
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0; // Diagonal elements represent the distance to itself (0 distance)
                }
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1; // Convert back the large value to -1 for vertices not connected directly
                }
            }
        }
    }
};

int main()
{
    return 0;
}