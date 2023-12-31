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
class Solution {
public:
    // Function to merge accounts using the disjoint set data structure.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> MapMail; // Map to store the index of the account for each email
        DisjointSet ds(n); // Create a DisjointSet with n elements

        // Step 1: Iterate through accounts and perform UnionBySize operation on emails with the same account.
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                // If the email is not in MapMail, assign the current account index to it.
                if (MapMail.find(mail) == MapMail.end())
                {
                    MapMail[mail] = i;
                }
                // If the email is already in MapMail, perform UnionBySize on the corresponding accounts.
                else
                {
                    ds.UnionBySize(MapMail[mail], i);
                }
            }
        }

        // Step 2: Create MergedMail to group emails based on their ultimate parent in the disjoint set.
        vector<string> MergedMail[n];
        for (auto it : MapMail)
        {
            string mail = it.first;
            int node = ds.FindUltimateParent(it.second);
            MergedMail[node].push_back(mail);
        }

        // Step 3: Build the final result by sorting and combining emails for each group.
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (MergedMail[i].size() != 0)
            {
                // Sort the emails for each group.
                sort(MergedMail[i].begin(), MergedMail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Add the name from the original account.
                // Add sorted emails for the current group.
                for (auto it : MergedMail[i])
                {
                    temp.push_back(it);
                }
                ans.push_back(temp); // Add the merged account to the final result.
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}