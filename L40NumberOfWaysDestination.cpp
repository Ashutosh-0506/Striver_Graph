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
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // Define a constant for modulo operation
        long long mod = 1e9 + 7;

        // Create an adjacency list to represent the graph
        vector<pair<long long, long long>> adj[n]; // Each element is a pair (adjacent node, time)

        // Populate the adjacency list based on the given roads
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Initialize distance array to store the minimum time to reach each node
        vector<long long> distance(n, 1e18); // Initially set to a large value
        distance[0] = 0;                     // Distance to the starting node is 0

        // Initialize ways array to store the number of ways to reach each node
        vector<long long> ways(n, 0); // Initially set to 0
        ways[0] = 1;                  // There is one way to reach the starting node

        // Create a priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0}); // Push the starting node with time 0 into the priority queue

        // Dijkstra's algorithm
        while (!pq.empty())
        {
            auto it = pq.top();
            long long time = it.first;
            long long node = it.second;
            pq.pop();

            // Explore neighbors of the current node
            for (auto iter : adj[node])
            {
                long long adjnode = iter.first;
                long long newtime = iter.second;

                // If a shorter path is found to the adjacent node
                if (time + newtime < distance[adjnode])
                {
                    distance[adjnode] = time + newtime;
                    pq.push({time + newtime, adjnode});
                    ways[adjnode] = ways[node] % mod; // Update the number of ways to reach the adjacent node
                }
                // If there are multiple paths with the same minimum time
                else if (time + newtime == distance[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod; // Accumulate the number of ways
                }
            }
        }

        // Return the number of ways to reach the last node modulo the constant
        return ways[n - 1] % mod;
    }
};

int main()
{
    return 0;
}