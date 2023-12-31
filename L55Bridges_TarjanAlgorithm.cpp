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
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited,
             vector<vector<int>> &ans, vector<int> &lowest, vector<int> &TimeOfIntersection, int Time)
    {
        // Mark the current node as visited
        visited[node] = true;

        // Assign the current time to TimeOfIntersection and lowest for the current node
        TimeOfIntersection[node] = Time;
        lowest[node] = Time;
        Time++;

        // Explore all neighbors of the current node
        for (auto it : adj[node])
        {
            if (it != parent)
            {
                if (!visited[it])
                {
                    // Recursive DFS call for the neighbor
                    dfs(it, node, adj, visited, ans, lowest, TimeOfIntersection, Time);

                    // Update the lowest time of the current node based on the neighbor's lowest time
                    lowest[node] = min(lowest[node], lowest[it]);

                    // Check for the condition of a critical connection
                    if (lowest[it] > TimeOfIntersection[node])
                    {
                        // If the lowest time of the neighbor is greater than the intersection time of the current node,
                        // then the edge (it, node) is a critical connection
                        ans.push_back({it, node});
                    }
                }
                else
                {
                    // If the neighbor is already visited, update the lowest time of the current node
                    lowest[node] = min(lowest[node], lowest[it]);
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // Initialize the adjacency list and visited array
        vector<int> adj[n];
        vector<bool> visited(n, false);

        // Initialize the result vector to store critical connections
        vector<vector<int>> ans;

        // Build the adjacency list from the given connections
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Initialize arrays to store lowest time and time of intersection for each node
        vector<int> lowest(n, 0);
        vector<int> TimeOfIntersection(n, 0);

        // Initialize time and start DFS from the first node
        int Time = 1;
        dfs(0, -1, adj, visited, ans, lowest, TimeOfIntersection, Time);

        // Return the vector containing critical connections
        return ans;
    }
};

int main()
{
    return 0;
}