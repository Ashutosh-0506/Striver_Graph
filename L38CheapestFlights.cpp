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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Create an adjacency list to represent the graph (flights)
        vector<pair<int, int>> adj[n]; // Stores {Adj Node, Price}
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Initialize the distance array to store the minimum cost to reach each node
        vector<int> distance(n, 1e9); // Initialize with a large value
        distance[src] = 0;            // The cost to reach the source node is 0

        // Create a queue to perform BFS (Dijkstra's algorithm)
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // Stores {stops, {node, cost}}

        // Perform BFS until the queue is empty
        while (!q.empty())
        {
            auto it = q.front();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            // If the number of stops is less than or equal to k, explore neighbors
            if (stop <= k)
            {
                for (auto iter : adj[node])
                {
                    int adjnode = iter.first;
                    int newcost = iter.second;

                    // If the new cost is less than the current known cost to reach the adjacent node
                    if (newcost + cost < distance[adjnode])
                    {
                        distance[adjnode] = cost + newcost;

                        // Push the updated information into the queue for further exploration
                        q.push({stop + 1, {adjnode, (cost + newcost)}});
                    }
                }
            }
        }

        // If the cost to reach the destination is still the initialized large value, it means it's not reachable
        if (distance[dst] == 1e9)
        {
            return -1;
        }

        // Return the minimum cost to reach the destination
        return distance[dst];
    }
};

int main()
{
    return 0;
}