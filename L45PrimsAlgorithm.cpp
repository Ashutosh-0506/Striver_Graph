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
#include<bits/stdc++.h>
using namespace ::std;
 class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Priority queue to store pairs of weight and node, sorted by weight in ascending order.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Vector to keep track of visited nodes.
        vector<bool> visited(V, false);

        // Initialize the priority queue with the starting node (0) and weight 0.
        pq.push({0, 0}); // Weight, node

        // Variable to store the sum of weights of MST.
        int sum = 0;

        // Main loop for Prim's algorithm.
        while (!pq.empty())
        {
            // Extract the node with the minimum weight.
            auto it = pq.top();
            int wt = it.first;    // Weight of the edge.
            int node = it.second; // Node.

            pq.pop();

            // If the node is not visited yet, process it.
            if (!visited[node])
            {
                // Mark the node as visited.
                visited[node] = true;

                // Add the weight to the sum.
                sum += wt;

                // Iterate through the adjacent nodes of the current node.
                for (auto iter : adj[node])
                {
                    int adjnode = iter[0];    // Adjacent node.
                    int adjweight = iter[1];  // Weight of the edge to the adjacent node.

                    // If the adjacent node is not visited, add it to the priority queue.
                    if (!visited[adjnode])
                    {
                        pq.push({adjweight, adjnode});
                    }
                }
            }
        }

        // Return the sum of weights of the Minimum Spanning Tree.
        return sum;
    }
};

int main()
{
return 0;
}