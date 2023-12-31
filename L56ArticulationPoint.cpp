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
    // Depth First Search (DFS) function to find articulation points in a graph
    void dfs(int node, int parent, vector<bool> &visited, vector<int> &lowest, vector<int> &timeofinsertion, vector<bool> &marked, vector<int> adj[], int Time)
    {
        // Mark the current node as visited
        visited[node] = true;

        // Initialize the lowest and time of insertion for the current node
        lowest[node] = Time;
        timeofinsertion[node] = Time;

        // Increment the time
        Time++;

        // Variable to count the number of children of the current node
        int child = 0;

        // Iterate through the adjacent nodes of the current node
        for (auto it : adj[node])
        {
            // Check if the adjacent node is not the parent (to avoid going back to the parent)
            if (it != parent)
            {
                // If the adjacent node is not visited, perform DFS on it
                if (!visited[it])
                {
                    dfs(it, node, visited, lowest, timeofinsertion, marked, adj, Time);

                    // Update the lowest value for the current node based on its children
                    lowest[node] = min(lowest[node], lowest[it]);

                    // Check if the lowest value of the adjacent node is greater than or equal
                    // to the time of insertion of the current node. If true, it's an articulation point.
                    if (lowest[it] >= timeofinsertion[node] && parent != -1)
                    {
                        marked[node] = true;
                    }

                    // Increment the child count
                    child++;
                }
                else
                {
                    // If the adjacent node is already visited, update the lowest value for the current node
                    lowest[node] = min(lowest[node], timeofinsertion[it]);
                }
            }
        }

        // Check if the current node is the root and has more than one child
        if ((parent == -1) && (child > 1))
        {
            marked[node] = true;
        }
    }

public:
    // Function to find articulation points in a graph
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Initialize vectors and variables
        vector<bool> visited(n, false);
        vector<int> lowest(n, 0);
        vector<int> timeofinsertion(n, 0);
        vector<int> ans;
        vector<bool> marked(n + 1, false);
        int Time = 1;

        // Iterate through all nodes in the graph
        for (int i = 0; i < n; i++)
        {
            // If the current node is not visited, perform DFS on it
            if (!visited[i])
            {
                dfs(i, -1, visited, lowest, timeofinsertion, marked, adj, Time);
            }
        }

        // Collect the nodes marked as articulation points
        for (int i = 0; i < n; i++)
        {
            if (marked[i])
            {
                ans.push_back(i);
            }
        }

        // If no articulation points are found, return {-1}
        if (ans.size() == 0)
        {
            return {-1};
        }

        // Return the vector of articulation points
        return ans;
    }
};

int main()
{
    return 0;
}