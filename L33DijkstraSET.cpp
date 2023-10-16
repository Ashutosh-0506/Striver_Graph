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
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Creating a set to store pairs of integers (distance, node).
        set<pair<int, int>> st;

        // Creating a vector to store distances from the source vertex to all other vertices, initializing all distances to a large value.
        vector<int> distance(V, 1e9);

        // Setting the distance of the source vertex as 0 and inserting it into the set.
        distance[S] = 0;
        st.insert({0, S});

        // Implementing the Dijkstra's algorithm.
        while (!st.empty())
        {
            // Extracting the element with the smallest distance from the set.
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            // Iterating through the adjacency list of the current node.
            for (auto tt : adj[node])
            {
                // Extracting the adjacent node and the corresponding edge weight.
                int newnode = tt[0];
                int newdis = tt[1];

                // Checking if the new path is shorter than the currently known path to the adjacent node.
                if (dis + newdis < distance[newnode])
                {
                    // If the distance to the adjacent node is not the initial large value, remove it from the set.
                    if (distance[newnode] != 1e9)
                    {
                        st.erase({distance[newnode], newnode});
                    }

                    // Updating the distance to the adjacent node and inserting it into the set.
                    distance[newnode] = dis + newdis;
                    st.insert({distance[newnode], newnode});
                }
            }
        }

        // Returning the vector containing the shortest distances from the source vertex to all other vertices.
        return distance;
    }
};
                                        
int main()
{
    return 0;
}