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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // Matrix to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Variable to store the current count of islands
        int count = 0;

        // Vector to store the results after each operation
        vector<int> ans;

        // Disjoint Set data structure to efficiently perform union-find operations
        DisjointSet ds(n * m);

        // Iterate through each operation in the 'operators' vector
        for (auto it : operators)
        {
            // Extract the row and column values from the current operation
            int row = it[0];
            int col = it[1];

            // Check if the current cell has not been visited
            if (!visited[row][col])
            {
                // Mark the cell as visited, increase the island count
                visited[row][col] = true;
                count++;

                // Define directions to check neighbors (up, right, down, left)
                int delrow[] = {1, 0, -1, 0};
                int delcol[] = {0, 1, 0, -1};

                // Iterate through the four possible neighboring cells
                for (int i = 0; i < 4; i++)
                {
                    // Calculate the coordinates of the neighboring cell
                    int newrow = row + delrow[i];
                    int newcol = col + delcol[i];

                    // Check if the neighboring cell is within the grid bounds and has been visited
                    if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && visited[newrow][newcol])
                    {
                        // Calculate node numbers for the current cell and its adjacent neighbor
                        int NodeNumber = row * m + col;
                        int AdjacentNodeNumber = newrow * m + newcol;

                        // Check if the nodes are not already part of the same connected component
                        if (ds.FindUltimateParent(NodeNumber) != ds.FindUltimateParent(AdjacentNodeNumber))
                        {
                            // If not, decrease the island count and union the nodes
                            count--;
                            ds.UnionByRank(NodeNumber, AdjacentNodeNumber);
                        }
                    }
                }
            }

            // Push the current island count into the result vector
            ans.push_back(count);
        }

        // Return the vector containing the island counts after each operation
        return ans;
    }
};

int main()
{

    return 0;
}