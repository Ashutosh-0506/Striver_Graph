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
    // Storing a graph in Adjacency Matrix Format
    int n; // Number of nodes
    int m; // Number of edges
    cin >> n >> m;

    // Creating an Adjacency Matrix
    int adj[n + 1][n + 1] = {0}; // Initialize the matrix with 0

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Mark the edge between u and v as present
        adj[u][v] = 1;
        adj[v][u] = 1; // Since it's an undirected graph
    }

    return 0;
}