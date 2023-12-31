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
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // Initialize a queue to perform BFS
        queue<pair<int, int>> q;
        // Push the starting state: step 0, starting node value
        q.push({0, start}); //{step, node}

        // Define a modulo value for preventing overflow
        int MOD = 1e5;

        // Initialize an array to store minimum distances to each node
        vector<int> distance(1e5, 1e9);
        // Distance to the starting node is 0
        distance[start] = 0;

        // Perform BFS
        while (!q.empty())
        {
            // Get the current state from the front of the queue
            auto it = q.front();
            int step = it.first;
            int node = it.second;
            q.pop();

            // Explore all possible multiplications with elements from 'arr'
            for (auto iter : arr)
            {
                // Calculate the next node value after multiplication
                int nextNode = (node * iter) % MOD;

                // If a shorter path to the next node is found
                if (distance[nextNode] > step + 1)
                {
                    // Update the distance array and push the new state to the queue
                    distance[nextNode] = step + 1;
                    q.push({step + 1, nextNode});
                }
            }
        }

        // If the distance to the target node is still the initial large value, no valid path exists
        if (distance[end] == 1e9)
        {
            return -1;
        }

        // Return the minimum number of steps to reach the target node
        return distance[end];
    }
};

int main()
{
    return 0;
}