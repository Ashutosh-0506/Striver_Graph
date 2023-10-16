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
    void bfs(int sr, int sc, vector<vector<bool>> &visited, vector<vector<int>> &image, int newcolor, int n, int m, int oldcolor)
    {
        visited[sr][sc] = true;
        image[sr][sc] = newcolor;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Up
            if (r - 1 >= 0 && r - 1 < n && c >= 0 && c < m && !visited[r - 1][c] && image[r - 1][c] == oldcolor)
            {
                visited[r - 1][c] = true; // Mark the neighbor as visited
                image[r - 1][c] = newcolor;
                q.push({r - 1, c}); // Enqueue the neighbor
            }

            // Down
            if (r + 1 >= 0 && r + 1 < n && c >= 0 && c < m && !visited[r + 1][c] && image[r + 1][c] == oldcolor)
            {
                visited[r + 1][c] = true;
                image[r + 1][c] = newcolor;
                q.push({r + 1, c});
            }

            // Right
            if (r >= 0 && r < n && c + 1 >= 0 && c + 1 < m && !visited[r][c + 1] && image[r][c + 1] == oldcolor)
            {
                visited[r][c + 1] = true;
                image[r][c + 1] = newcolor;
                q.push({r, c + 1});
            }

            // Left
            if (r >= 0 && r < n && c - 1 >= 0 && c - 1 < m && !visited[r][c - 1] && image[r][c - 1] == oldcolor)
            {
                visited[r][c - 1] = true;
                image[r][c - 1] = newcolor;
                q.push({r, c - 1});
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int oldcolor = image[sr][sc];
        int newcolor = color;
        bfs(sr, sc, visited, image, newcolor, n, m, oldcolor);
        return image;
    }
};
int main()
{
    return 0;
}