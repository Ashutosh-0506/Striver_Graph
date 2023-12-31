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
    vector<int> Parent;
    vector<int> Rank;
    vector<int> Size;

public:
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
void Check(DisjointSet &ds, int a, int b)
{
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
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);
    Check(ds, 3, 7);
    ds.UnionBySize(3, 7);
    Check(ds, 3, 7);
    return 0;
}