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
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // Step 1: Make The Graph List
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Make Distance vector
        int INF = 1e9;
        vector<int> distance(N, INF);
        distance[src] = 0;
        queue<int> q;
        q.push(src);

        // Step 3: Apply BFS
        while (!q.empty())
        {
            int node =q.front();
            q.pop();
            for (auto it : adj[node])
            {
                int v = it;
                if (distance[node] + 1 < distance[v])
                {
                    distance[v] = distance[node] + 1;
                    q.push(it);
                }
            }
        }

        // Correct the INF values in the distance vector
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