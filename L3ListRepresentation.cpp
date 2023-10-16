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

int main()
{
    // Storing a graph in Adjacency List Format using vectors
    int n; // Number of nodes
    int m; // Number of edges
    cin >> n >> m; // Input the number of nodes and edges

    // Creating an Adjacency List using vectors
    vector<int> adj[n + 1]; // Create a vector array of size n+1 to store adjacency lists

    // Loop through each edge
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // Input the two nodes representing the edge

        // Add v to the adjacency list of u and vice versa
        adj[u].push_back(v); // Add v to the list of neighbors of u
        adj[v].push_back(u); // Add u to the list of neighbors of v (undirected graph)
    }

    // At this point, the adjacency list 'adj' contains the neighbors of each node

    return 0;
}
