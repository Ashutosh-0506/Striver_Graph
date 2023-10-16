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
    // Private helper function for DFS traversal
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {
        // Mark the current node as visited
        visited[node] = true;
        
        // Add the current node to the result list
        ans.push_back(node);
        
        // Traverse through the adjacent nodes of the current node
        for (auto it : adj[node])
        {
            // If the adjacent node is not visited, recursively call dfs on it
            if (!visited[it])
            {
                dfs(it, adj, visited, ans);
            }
        }
    }

public:
    // Public method to perform DFS traversal on the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Initialize a vector to track visited nodes
        vector<bool> visited(V, false);
        
        // Initialize a vector to store the DFS traversal result
        vector<int> ans;
        
        int node = 0;  // Starting node for DFS traversal
        
        // Mark the starting node as visited
        visited[node] = true;
        
        // Call the private dfs function to perform the traversal
        dfs(node, adj, visited, ans);
        
        // Return the DFS traversal result
        return ans;
    }
};

int main()
{
    return 0;
}