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
    bool bfs(int source, vector<int> adj[], vector<bool> &visited)
    {
        visited[source] = true; // Mark the current node as visited
        queue<pair<int, int>> q;
        q.push({source, -1}); // Push the current node and its parent (-1 for root)

        while (!q.empty())
        {
            int node = q.front().first; // Current node
            int parent = q.front().second; // Parent node
            q.pop();

            for (auto it : adj[node]) // Loop through all adjacent nodes of the current node
            {
                if (!visited[it]) // If the adjacent node is not visited
                {
                    visited[it] = true; // Mark it as visited
                    q.push({it, node}); // Push the adjacent node and its parent into the queue
                }
                else if (parent != it) // If the adjacent node is visited and not the parent
                {
                    return true; // There is a cycle in the graph
                }
            }
        }
        return false; // No cycle was found
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false); // Create an array to track visited nodes
        for (int i = 0; i < V; i++)
        {
            if (!visited[i]) // If the node is not visited yet
            {
                if (bfs(i, adj, visited) == true) // Call BFS for this node
                {
                    return true; // If a cycle is found, return true
                }
            }
        }
        return false; // If no cycle is found, return false
    }
};

int main()
{
    return 0;
}