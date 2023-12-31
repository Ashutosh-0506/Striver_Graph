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
// Implementation of Disjoint Set data structure
class DisjointSet
{
public:
    vector<int> Parent;
    vector<int> Rank;
    vector<int> Size;

    // Constructor
    DisjointSet(int n)
    {
        Rank.resize(n + 1, 0);
        Parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    // Function to find the ultimate parent
    int FindUltimateParent(int node)
    {
        if (node == Parent[node])
        {
            return node;
        }
        return (Parent[node] = FindUltimateParent(Parent[node])); // Path compression
    }

    // Union by rank
    void UnionByRank(int u, int v)
    {
        int Ult_U = FindUltimateParent(u);
        int Ult_V = FindUltimateParent(v);

        // If both nodes belong to the same component, do nothing
        if (Ult_U == Ult_V)
        {
            return;
        }

        // Merge the smaller rank set into the larger rank set
        if (Rank[Ult_U] < Rank[Ult_V])
        {
            Parent[Ult_U] = Ult_V;
        }
        else if (Rank[Ult_U] > Rank[Ult_V])
        {
            Parent[Ult_V] = Ult_U;
        }
        else
        {
            // If ranks are equal, choose any set as the parent and increment the rank
            Parent[Ult_V] = Ult_U;
            Rank[Ult_U]++;
        }
    }

    // Union by Size
    void UnionBySize(int u, int v)
    {
        int Ult_U = FindUltimateParent(u);
        int Ult_V = FindUltimateParent(v);

        // If both nodes belong to the same component, do nothing
        if (Ult_U == Ult_V)
        {
            return;
        }

        // Merge the smaller size set into the larger size set
        if (Size[Ult_U] > Size[Ult_V])
        {
            Parent[Ult_V] = Ult_U;
            Size[Ult_U] += Size[Ult_V];
        }
        else
        {
            Parent[Ult_U] = Ult_V;
            Size[Ult_V] += Size[Ult_U];
        }
    }
};

// Solution class
class Solution
{
public:
    // Function to determine the number of connected components in a network
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int m = connections.size();
        int count = -1;

        // If the number of connections is less than n-1, it's impossible to connect all nodes
        if (m < n - 1)
        {
            return count;
        }

        DisjointSet ds(n);

        // Union operation for each connection
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            ds.UnionByRank(u, v);
        }

        // Count the number of unique ultimate parents, which represent connected components
        for (int i = 0; i < n; i++)
        {
            if (ds.Parent[i] == i)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}