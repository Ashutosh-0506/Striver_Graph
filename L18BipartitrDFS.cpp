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
    bool dfs(int start, vector<int> &color, vector<vector<int>> &graph)
    {
        color[start] = 0;
        for (auto it : graph[start])
        {
            if (color[it] == -1)
            {
                color[it] = !color[start];
                dfs(it, color, graph);
            }
            else if (color[it] == color[start])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, color, graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}