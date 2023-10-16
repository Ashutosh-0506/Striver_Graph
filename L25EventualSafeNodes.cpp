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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();  // Number of vertices in the graph
        vector<int> adj[V];   // Create an adjacency list for the graph

        // Step 1: Create the transpose of the given graph
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);  // Reverse the edges by swapping i and graph[i][j]
            }
        }

        vector<int> indegree(V);  // Create an array to store indegree of each vertex
        queue<int> q;             // Create a queue for topological sorting

        // Step 2: Calculate the indegree of each vertex
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;  // Increment indegree for each vertex reachable from i
            }
        }

        // Step 3: Initialize the queue with nodes having indegree of 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);  // Add nodes with indegree 0 to the queue
            }
        }

        vector<int> ans;  // Create a vector to store the eventual safe nodes

        // Step 4: Perform topological sorting using the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);  // Add the current node to the answer

            // Update indegrees of adjacent nodes
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);  // If indegree becomes 0, add it to the queue
                }
            }
        }

        sort(ans.begin(), ans.end());  // Sort the answer vector
        return ans;  // Return the list of eventual safe nodes in sorted order
    }
};

int main()
{
return 0;
}