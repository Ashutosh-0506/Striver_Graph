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
        // Creating a priority queue to store pairs of integers (distance, node).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Creating a vector to store distances from the source vertex to all other vertices.
        vector<int> distance(V, INT_MAX);

        // Setting the distance of the source vertex as 0 and pushing it into the priority queue.
        distance[S] = 0;
        pq.push({0, S});

        // Implementing the Dijkstra's algorithm.
        while (!pq.empty())
        {
            // Extracting the minimum distance and corresponding node from the priority queue.
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Iterating through the adjacency list of the current node.
            for (auto it : adj[node])
            {
                // Extracting the adjacent node and the corresponding edge weight.
                int newnode = it[0];
                int newdis = it[1];

                // Checking if the new path is shorter than the currently known path to the adjacent node.
                if (dis + newdis < distance[newnode])
                {
                    // Updating the distance to the adjacent node and pushing it into the priority queue.
                    distance[newnode] = dis + newdis;
                    pq.push({distance[newnode], newnode});
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