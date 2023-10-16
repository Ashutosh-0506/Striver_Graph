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
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // Step 1: Create Graph
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort (Kahn's Algorithm)
        stack<int> st;
        vector<int> inDegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                int v = it.first;
                inDegree[v]++;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (inDegree[i] == 0)
            {
                st.push(i);
            }
        }

        // Step 3: Initialize Distance
        const int INF = 1e9;
        vector<int> distance(N, INF);
        int src = 0;
        distance[src] = 0;

        // Step 4: Relax Edges (using Priority Queue)
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (distance[node] + wt < distance[v])
                {
                    distance[v] = distance[node] + wt;
                }
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    st.push(v);
                }
            }
        }

        // Step 5: Handle nodes with no reachable paths
        for (int i = 0; i < N; i++)
        {
            if (distance[i] == INF)
            {
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