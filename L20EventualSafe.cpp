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
    // Depth-first search function
    bool dfs(int node, vector<bool> &visited, vector<bool> &path, vector<bool> &check, vector<vector<int>> &graph)
    {
        // Mark the current node as part of the current path and visited
        path[node] = true;
        visited[node] = true;
        check[node] = false;

        // Explore neighbors of the current node
        for (auto it : graph[node])
        {
            // If the neighbor is not visited, recursively explore it
            if (!visited[it])
            {
                if (dfs(it, visited, path, check, graph))
                {
                    return true; // If a cycle is detected in the recursion, return true
                }
            }
            // If the neighbor is part of the current path, a cycle is detected
            else if (path[it])
            {
                return true;
            }
        }

        // No cycle detected in the current path, mark the node as safe
        check[node] = true;
        path[node] = false;
        return false;
    }

public:
    // Function to find eventually safe nodes
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> visited(n, false); // Keep track of visited nodes
        vector<bool> path(n, false);    // Keep track of nodes in the current path
        vector<bool> check(n, false);   // Keep track of nodes that are eventually safe
        vector<int> ans;                // Resultant vector to store eventually safe nodes

        // Iterate through all nodes to perform DFS
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, path, check, graph);
            }
        }

        // Add nodes that are eventually safe to the answer
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                ans.push_back(i);
            }
        }

        return ans; // Return the list of eventually safe nodes
    }
};

int main()
{
    return 0;
}