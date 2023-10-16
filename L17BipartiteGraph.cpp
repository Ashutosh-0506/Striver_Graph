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
    // This function performs a breadth-first search (BFS) traversal
    // to check if a given component of the graph is bipartite.
    bool bfs(int start, vector<int> &color, vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Assign color 0 to the starting node.

        // Start BFS traversal
        while (!q.empty())
        {
            int node = q.front(); // Get the front node from the queue.
            q.pop();

            // Explore neighbors of the current node.
            for (auto it : graph[node])
            {
                if (color[it] == -1) // If the neighbor has not been colored yet.
                {
                    color[it] = !color[node]; // Color the neighbor with the opposite color.
                    q.push(it);               // Add the neighbor to the queue for further exploration.
                }
                else if (color[it] == color[node]) // If the neighbor has the same color as the current node.
                {
                    return false; // The graph is not bipartite in this case.
                }
            }
        }
        return true; // All nodes in this component have been colored in a valid way.
    }

public:
    // This function checks if the entire graph is bipartite by checking each connected component.
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize colors for all nodes as -1 (not colored).

        // Iterate through each node in the graph to handle all connected components.
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1) // If the node has not been colored yet, start a new component.
            {
                if (!bfs(i, color, graph)) // Call BFS to check if the component is bipartite.
                {
                    return false; // If any component is not bipartite, the graph is not bipartite.
                }
            }
        }
        return true; // All connected components are bipartite, so the graph is bipartite.
    }
};

int main()
{
    return 0;
}