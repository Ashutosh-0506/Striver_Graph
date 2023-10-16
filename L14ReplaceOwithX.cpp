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
    void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        visited[row][col] = true;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, visited, mat);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Check column boundary
        for (int i = 0; i < n; i++)
        {
            // Col 1
            if (mat[i][0] == 'O')
            {
                dfs(i, 0, visited, mat);
            }

            // Col m-1
            if (mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, mat);
            }
        }

        // Check Row Boundary
        for (int j = 0; j < m; j++)
        {
            // Row 1
            if (mat[0][j] == 'O')
            {
                dfs(0, j, visited, mat);
            }

            // Row n-1
            if (mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, visited, mat);
            }
        }

        // Convert Non visited 'O' to 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
int main()
{
    return 0;
}