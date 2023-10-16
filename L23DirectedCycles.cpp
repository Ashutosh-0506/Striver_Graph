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
 class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // Create a queue for BFS (Breadth-First Search) traversal.
        queue<int> q;

        // Create a vector to store the indegree of each node.
        vector<int> indegree(V);

        // Calculate the indegree of each node by iterating through the adjacency list.
        for (int i = 0; i < V; i++) {
            for (auto tt : adj[i]) {
                indegree[tt]++;
            }
        }

        // Push nodes with an indegree of 0 (no incoming edges) into the queue.
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Counter to keep track of the number of nodes processed.

        // Perform BFS traversal.
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Iterate through the adjacent nodes of the current node.
            for (auto it : adj[node]) {
                indegree[it]--;

                // If the indegree of an adjacent node becomes 0, push it into the queue.
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the count of processed nodes is not equal to the total number of nodes (V),
        // it means there is a cycle in the graph, and the function returns true.
        return (count != V);
    }
};

int main()
{
return 0;
}