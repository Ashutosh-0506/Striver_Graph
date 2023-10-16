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
class Solution {
private:
    // Depth-First Search function
    void dfs(int node, vector<int> adjL[], vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = true;

        // Explore neighbors of the current node
        for (auto it : adjL[node]) {
            // If the neighbor hasn't been visited, recursively visit it
            if (!visited[it]) {
                dfs(it, adjL, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of vertices/nodes in the graph
        int v = isConnected.size();

        // Step 1: Convert the adjacency matrix to an adjacency list

        // Create an array of vectors to represent the adjacency list
        vector<int> adjL[v];
        
        // Populate the adjacency list based on the adjacency matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                // If there's a connection between nodes i and j and they are not the same node
                if (isConnected[i][j] == 1 && i != j) {
                    // Add j to the adjacency list of i and vice versa
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        // Step 2: Find the number of connected components using DFS

        // Create a vector to track visited nodes
        vector<bool> visited(v, false);

        // Initialize a counter to keep track of the number of connected components
        int count = 0;

        // Iterate through all nodes
        for (int i = 0; i < v; i++) {
            // If the current node hasn't been visited, start a new DFS from it
            if (!visited[i]) {
                // Increment the counter since a new connected component is found
                count++;
                // Perform DFS from the current node and mark visited nodes
                dfs(i, adjL, visited);
            }
        }

        // Step 3: Return the count of connected components
        return count;
    }
};

int main()
{
    return 0;
}