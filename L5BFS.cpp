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
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Create a vector to track visited nodes, initialized as not visited (0).
        vector<bool> visited(V, 0);

        // Create a vector to store the BFS traversal result.
        vector<int> ans;

        // Create a queue for BFS traversal.
        queue<int> q;

        // Start BFS from the first node (node 0).
        q.push(0);

        // Mark the first node as visited.
        visited[0] = 1;

        // Perform BFS traversal while the queue is not empty.
        while (!q.empty())
        {
            // Get the front node from the queue.
            int node = q.front();

            // Remove the processed node from the queue.
            q.pop();

            // Add the current node to the BFS traversal result.
            ans.push_back(node);

            // Explore neighbors of the current node.
            for (auto it : adj[node])
            {
                // If the neighbor is not visited, add it to the queue and mark as visited.
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        // Return the BFS traversal result.
        return ans;
    }
};

int main()
{
    return 0;
}