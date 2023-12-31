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
    // Function to find the size of the largest island
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();   // Size of the grid
        DisjointSet ds(n * n); // Create a DisjointSet to track connected components

        // Step 1: Union all connected '1' cells in the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int delrow[] = {1, 0, -1, 0}; // Changes in row for 4 directions
                    int delcol[] = {0, 1, 0, -1}; // Changes in column for 4 directions
                    for (int k = 0; k < 4; k++)
                    {
                        int newrow = delrow[k] + i; // New row index
                        int newcol = delcol[k] + j; // New column index
                        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n && grid[newrow][newcol] == 1)
                        {
                            int NodeNumber = i * n + j;                     // Current cell index
                            int AdjacentNodeNumber = newrow * n + newcol;   // Adjacent cell index
                            ds.UnionBySize(NodeNumber, AdjacentNodeNumber); // Union the connected components
                        }
                    }
                }
            }
        }

        // Step 2: Find the largest island by checking neighboring '0' cells
        int maxx = 0; // Variable to store the size of the largest island
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int delrow[] = {1, 0, -1, 0}; // Changes in row for 4 directions
                    int delcol[] = {0, 1, 0, -1}; // Changes in column for 4 directions
                    set<int> components;          // Set to store unique connected component indices
                    for (int k = 0; k < 4; k++)
                    {
                        int newrow = delrow[k] + i; // New row index
                        int newcol = delcol[k] + j; // New column index
                        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n && grid[newrow][newcol] == 1)
                        {
                            int AdjacentNodeNumber = newrow * n + newcol;                 // Adjacent cell index
                            components.insert(ds.FindUltimateParent(AdjacentNodeNumber)); // Add connected component to set
                        }
                    }

                    int sum = 0; // Variable to calculate the size of the combined components
                    for (auto it : components)
                    {
                        sum += ds.Size[it]; // Sum up the sizes of the connected components
                    }
                    maxx = max(maxx, sum + 1); // Update the size of the largest island
                }
            }
        }

        // Step 3: Find the size of the largest connected component
        for (int i = 0; i < n * n; i++)
        {
            maxx = max(maxx, ds.Size[ds.FindUltimateParent(i)]); // Update the size of the largest connected component
        }

        // Return the size of the largest island
        return maxx;
    }
};

int main()
{
    return 0;
}