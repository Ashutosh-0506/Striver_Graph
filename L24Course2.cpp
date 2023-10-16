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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V]; // Create an adjacency list for the courses.

        int n = prerequisites.size(); // Get the number of prerequisites.

        // Populate the adjacency list based on the prerequisites.
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> indegree(V); // Create a vector to store the indegree of each course.
        queue<int> q;

        // Calculate the indegree of each course by iterating through the adjacency list.
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Push courses with an indegree of 0 (no prerequisites) into the queue.
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans; // Create a vector to store the final course order.

        // Perform BFS traversal to find a valid course order.
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node); // Add the course to the order.

            // Iterate through the courses that depend on the current course.
            for (auto it : adj[node]) {
                indegree[it]--;

                // If the indegree of a course becomes 0, add it to the queue.
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the order contains all courses (ans.size() == V), return the order.
        // Otherwise, return an empty vector to indicate that no valid order exists.
        if (ans.size() == V) {
            // Reverse the order to obtain the correct course sequence.
            reverse(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }
};

int main()
{
return 0;
}