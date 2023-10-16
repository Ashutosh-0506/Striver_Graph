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
class Solution {
private:
    void dfs(int node, stack<int> &st, vector<bool> &visited, vector<pair<int, int>> adj[]) {
        visited[node] = true;
        for (auto it : adj[node]) {
            dfs(it.first, st, visited, adj);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // Step 1: Create Graph
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        stack<int> st;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, st, visited, adj);
            }
        }

        // Step 3: Initialize Distance
        vector<int> distance(N, INT_MAX);
        int src = 0;
        distance[src] = 0;

        // Step 4: Relax Edges
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (distance[node] != INT_MAX && distance[node] + wt < distance[v]) {
                    distance[v] = distance[node] + wt;
                }
            }
        }

        // Step 5: Handle nodes with no reachable paths
        for (int i = 0; i < N; i++) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }

        return distance;
    }
};
int main()
{
    return 0;
}