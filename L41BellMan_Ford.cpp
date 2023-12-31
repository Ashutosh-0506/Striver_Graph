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
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        // Initialize a vector to store the distances from the source to each vertex.
        // Set initial distances to a large value (1e8) except for the source vertex, which is set to 0.
        vector<int> distance(V, 1e8);
        distance[S] = 0;

        // Bellman-Ford algorithm
        // Iterate V-1 times to relax edges and find shortest paths.
        for (int i = 0; i < V - 1; i++)
        {
            // Iterate through all edges in the graph.
            for (auto it : edges)
            {
                int u = it[0];      // Source vertex of the edge
                int v = it[1];      // Destination vertex of the edge
                int weight = it[2]; // Weight (cost) of the edge

                // Relaxation step: Update the distance to the destination vertex if a shorter path is found.
                if ((distance[u] != 1e8) && (distance[u] + weight < distance[v]))
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        // Check for negative cycles
        // Iterate through all edges one more time
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int weight = it[2];

            // If a shorter path is still found, then there is a negative cycle in the graph.
            if ((distance[u] != 1e8) && (distance[u] + weight < distance[v]))
            {
                // Return a special value (-1) to indicate the presence of a negative cycle.
                return {-1};
            }
        }

        // Return the vector containing the shortest distances from the source vertex to all other vertices.
        return distance;
    }
};
//O(E*V) this algorithm takes slightly more time than Dijkstra's algorithm


int main()
{
    return 0;
}