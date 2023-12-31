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
    // Depth-first search to fill the stack with nodes in order of their finishing times.
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }

    // Second depth-first search to traverse the transpose of the graph and count SCCs.
    void dfs2(int node, vector<vector<int>> &adjT, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adjT[node])
        {
            if (!visited[it])
            {
                dfs2(it, adjT, visited);
            }
        }
    }

public:
    // Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<bool> visited(V, false);
        stack<int> st;

        // Step 1: Perform the first DFS to fill the stack with nodes in order of finishing times.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        // Step 2: Create the transpose of the graph.
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        // Step 3: Traverse the transpose using the finishing times to count SCCs.
        int SCC = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                SCC++;
                dfs2(node, adjT, visited);
            }
        }

        return SCC;
    }
};

int main()
{
    return 0;
}