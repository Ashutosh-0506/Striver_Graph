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
// Definition of the DisjointSet class
class DisjointSet
{
    // Private member variables
    vector<int> Parent; // Array to store the parent of each node
    vector<int> Rank;   // Array to store the rank of each node

public:
    // Constructor to initialize the DisjointSet
    DisjointSet(int n)
    {
        Rank.resize(n + 1, 0); // Initialize the rank array with zeros
        Parent.resize(n + 1);  // Initialize the parent array with node numbers

        // Initialize each node as its own parent initially
        for (int i = 0; i <= n; i++)
        {
            Parent[i] = i;
        }
    }

    // Function to find the ultimate parent of a node with path compression
    int FindUltimateParent(int node)
    {
        // If the node is its own parent, return the node
        if (node == Parent[node])
        {
            return node;
        }

        // Perform path compression by updating the parent of the current node
        return (Parent[node] = FindUltimateParent(Parent[node]));
    }

    // Union by rank to merge two components based on their ranks
    void UnionByRank(int u, int v)
    {
        // Find the ultimate parent of each node
        int Ult_U = FindUltimateParent(u);
        int Ult_V = FindUltimateParent(v);

        // If both nodes belong to the same component, do nothing
        if (Ult_U == Ult_V)
        {
            return;
        }

        // If the rank of the first component is less than the rank of the second
        if (Rank[Ult_U] < Rank[Ult_V])
        {
            Parent[Ult_U] = Ult_V; // Set the ultimate parent of the first component to the second
        }
        // If the rank of the second component is less than the rank of the first
        else if (Rank[Ult_U] > Rank[Ult_V])
        {
            Parent[Ult_V] = Ult_U; // Set the ultimate parent of the second component to the first
        }
        // If the ranks are equal, arbitrarily choose one as the parent and increase its rank
        else
        {
            Parent[Ult_V] = Ult_U; // Set the ultimate parent of the second component to the first
            Rank[Ult_U]++;        // Increase the rank of the first component
        }
    }
};

// Function to check if two nodes are in the same component
void Check(DisjointSet &ds, int a, int b)
{
    // If the ultimate parent of both nodes is the same, they are in the same component
    if (ds.FindUltimateParent(a) == ds.FindUltimateParent(b))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
}

int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    Check(ds,3,7);
    ds.UnionByRank(3, 7);
    Check(ds,3,7);


    return 0;
}