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
    vector<int> Parent; // Array to store parent of each element
    vector<int> Rank;   // Array to store rank of each element for union by rank
    vector<int> Size;   // Array to store size of each set for union by size

public:
    // Constructor to initialize the Disjoint Set with 'n' elements
    DisjointSet(int n)
    {
        Rank.resize(n + 1, 0);
        Parent.resize(n + 1);
        Size.resize(n + 1);

        // Initialize each element as a separate set
        for (int i = 0; i <= n; i++)
        {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    // Function to find the ultimate parent of a set to which 'node' belongs
    int FindUltimateParent(int node)
    {
        // If 'node' is the parent, return 'node'
        if (node == Parent[node])
        {
            return node;
        }

        // Path compression: Update the parent to the ultimate parent and return it
        return (Parent[node] = FindUltimateParent(Parent[node]));
    }

    // Union by rank operation to merge sets 'u' and 'v'
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

    // Union by size operation to merge sets 'u' and 'v' based on set sizes
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
    // Function to find the number of provinces (connected components) in a graph
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);

        // Iterate through the adjacency matrix to perform union operations
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If there is a connection and the nodes are different, perform union
                if (isConnected[i][j] == 1 && i != j)
                {
                    ds.UnionBySize(i, j);
                }
            }
        }

        set<int> NumberofProvinces;

        // Collect the ultimate parent of each node and insert into the set
        for (int i = 0; i < n; i++)
        {
            NumberofProvinces.insert(ds.FindUltimateParent(i));
        }

        // Return the number of unique ultimate parents (number of provinces)
        return NumberofProvinces.size();
    }
};

int main()
{
    return 0;
}