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
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Creating an adjacency list to store the edges and weights
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        // Extracting the vertices and weight from the input edges
        int v = edges[i][0];
        int u = edges[i][1];
        int d = edges[i][2];
        // Adding edges to the adjacency list
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    // Initializing the distance vector with a large value
    vector<int> distance(n + 1, 1e9);
    // Setting the distance of the source node to 0
    distance[1] = 0;

    // Initializing the parent vector to keep track of the path
    vector<int> parent(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        parent[i] = i; // Initializing each node's parent as itself
    }

    // Using a priority queue to store the nodes in order of their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // Pushing the source node with a distance of 0

    // Dijkstra's algorithm loop
    while (!pq.empty())
    {
        int dis = pq.top().first;   // Current distance
        int node = pq.top().second; // Current node
        pq.pop();                   // Removing the node from the priority queue

        // Exploring the neighboring nodes of the current node
        for (auto it : adj[node])
        {
            int newnode = it.first; // Neighboring node
            int newdis = it.second; // Distance to the neighboring node

            // If the new distance is shorter than the previous recorded distance, update it
            if (dis + newdis < distance[newnode])
            {
                distance[newnode] = dis + newdis;      // Update the distance
                parent[newnode] = node;                // Update the parent node
                pq.push({distance[newnode], newnode}); // Push the new node into the priority queue
            }
        }
    }

    // If the distance to the final node is still at its initial large value, there is no path
    if (distance[n] == 1e9)
    {
        return {-1}; // Return -1 to indicate no path exists
    }

    // If a path exists, backtrack through the parent nodes to find the shortest path
    vector<int> ans;
    int node = n;
    while (parent[node] != node)
    {
        ans.push_back(node); // Push the current node to the path
        node = parent[node]; // Move to the parent node
    }
    ans.push_back(1);                // Add the source node to the path
    reverse(ans.begin(), ans.end()); // Reverse the path to get the correct order

    return ans; // Return the shortest path
}

int main()
{
    int n = 4, m = 5;
    vector<vector<int>> edges = {{1, 2, 24}, {1, 4, 20}, {3, 1, 3}, {4, 3, 12}, {2, 1, 24}};
    vector<int> result = shortestPath(n, m, edges);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

