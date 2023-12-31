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

    // Function to find parent
    int FindUltimateParent(int node)
    {
        if (node == Parent[node])
        {
            return node;
        }
        return (Parent[node] = FindUltimateParent(Parent[node]));
    }

    // Union by rank
    void UnionByRank(int u, int v)
    {
        int Ult_U = FindUltimateParent(u);
        int Ult_V = FindUltimateParent(v);

        // If both the nodes belong to the same component
        if (Ult_U == Ult_V)
        {
            return;
        }

        // else
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
            Parent[Ult_V] = Ult_U;
            Rank[Ult_U]++;
        }
    }
    // Union by Size
    void UnionBySize(int u, int v)
    {
        int Ult_U = FindUltimateParent(u);
        int Ult_V = FindUltimateParent(v);
        if (Ult_U == Ult_V)
        {
            return;
        }
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

class Solution
{
public:
    // Function to remove stones and find the number of remaining stones
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size(); // Number of stones
        int maxrow = 0;        // Maximum row index
        int maxcol = 0;        // Maximum column index

        // Step 1: Find the maximum row and column indices among stones
        for (auto it : stones)
        {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        DisjointSet ds(maxrow + maxcol + 1);  // Create a DisjointSet with enough space for rows and columns
        unordered_map<int, int> UniqueStones; // Map to store unique stone indices

        // Step 2: Union stones based on their rows and columns
        for (auto it : stones)
        {
            int NodeRow = it[0];
            int NodeCol = it[1] + maxrow + 1; // Offset column indices to avoid conflicts with row indices
            ds.UnionByRank(NodeRow, NodeCol); // Union stones based on rank
            UniqueStones[NodeRow] = 1;        // Mark row as a unique stone
            UniqueStones[NodeCol] = 1;        // Mark column as a unique stone
        }

        // Step 3: Count the number of distinct connected components (unique stones)
        int count = 0;
        for (auto it : UniqueStones)
        {
            if (ds.FindUltimateParent(it.first) == it.first)
            {
                count++;
            }
        }

        // Return the number of removed stones (initial stones - distinct connected components)
        return n - count;
    }
};
int main()
{
    return 0;
}