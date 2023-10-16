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
    // Function to check if it's possible to finish all courses given prerequisites.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0; // Counter to keep track of the number of courses that can be taken.

        // Perform BFS traversal to determine if all courses can be taken.
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Iterate through the courses that depend on the current course.
            for (auto it : adj[node]) {
                indegree[it]--;

                // If the indegree of a course becomes 0, add it to the queue.
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the count of courses that can be taken is equal to the total number of courses,
        // it means all courses can be finished, and the function returns true. Otherwise, it returns false.
        return (count == V);
    }
};

int main()
{
return 0;
}