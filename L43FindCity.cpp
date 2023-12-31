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
#include<bits/stdc++.h>
using namespace ::std;
 class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Step 1: Create adjacency matrix
        vector<vector<int>> adj(n, vector<int>(n, 1e9)); // Initialize with a large value (1e9) representing infinity
        for(auto it: edges) {
            int v = it[0];
            int u = it[1];
            int wt = it[2];
            adj[v][u] = wt;
            adj[u][v] = wt;
        }

        // Step 2: Apply Floyd-Warshall algorithm to find the minimum distances between all pairs of vertices
        for(int i = 0; i < n; i++) {
            adj[i][i] = 0; // Set the diagonal elements to 0 (distance from a vertex to itself is 0)
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                   adj[i][j] = min(adj[i][j], (adj[i][k] + adj[k][j])); // Update the minimum distance
                }
            }
        }

        // Step 3: Find the city with the minimum number of reachable cities within the distanceThreshold
        int cityNumber = -1;
        int cityCount = n;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= cityCount) {
                cityCount = count;
                cityNumber = i;
            }
        }

        return cityNumber;
    }
};

int main()
{
return 0;
}