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
// User function Template for C++

class Solution
{
private:
    // Helper function for depth-first search (DFS).
    void dfs(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[])
    {
        // Mark the current node as visited.
        visited[node] = true;

        // Explore all adjacent nodes that have not been visited yet.
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                // Recursively call DFS for unvisited adjacent nodes.
                dfs(it, visited, st, adj);
            }
        }

        // After visiting all adjacent nodes, push the current node onto the stack.
        st.push(node);
    }

    // Function to perform topological sorting.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Initialize a boolean array to keep track of visited nodes.
        vector<bool> visited(V, false);

        // Create a stack to store the topologically sorted nodes.
        stack<int> st;

        // Create a vector to store the final topological order.
        vector<int> ans;

        // Perform DFS from each unvisited node in the graph.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }

        // Pop elements from the stack to get the topological order.
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // Return the topological order as a vector.
        return ans;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];

        // Build the adjacency list based on the lexicographical order of characters.
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    // Add an edge from s1[ptr] to s2[ptr] in the adjacency list.
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        // Perform topological sorting to get the correct order of characters.
        vector<int> topo = topoSort(K, adj);

        string ans = "";

        // Convert the topological order to a string.
        for (auto it : topo)
        {
            ans = ans + char(it + 'a');
        }

        // Return the final topological order as a string.
        return ans;
    }
};

int main()
{
    return 0;
}