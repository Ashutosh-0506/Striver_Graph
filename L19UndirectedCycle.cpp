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
    // Depth-First Search function to detect cycles in a directed graph.
    bool dfs(int node, vector<bool> &visited, vector<bool> &path, vector<int> adj[])
    {
        // Mark the current node as visited and add it to the current DFS path.
        visited[node] = true;
        path[node] = true;

        // Explore each neighbor of the current node.
        for (auto neighbor : adj[node])
        {
            // If the neighbor has not been visited yet, perform DFS on it.
            if (!visited[neighbor])
            {
                if (dfs(neighbor, visited, path, adj))
                {
                    // If a cycle is found in the recursive call, propagate the result up the call stack.
                    return true;
                }
            }
            // If the neighbor has been visited and is part of the current path, a cycle is detected.
            else if (path[neighbor])
            {
                // Return true to indicate the presence of a cycle.
                return true;
            }
        }

        // Backtrack: Remove the current node from the DFS path as we move back.
        path[node] = false;

        // No cycle found in the current path starting from this node.
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> path(V, false);

        // Iterate through all nodes and perform DFS if not visited already.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, path, adj))
                {
                    // If a cycle is found from this node's DFS traversal, return true.
                    return true;
                }
            }
        }

        // No cycle found after traversing all nodes.
        return false;
    }
};

int main()
{
    return 0;
}