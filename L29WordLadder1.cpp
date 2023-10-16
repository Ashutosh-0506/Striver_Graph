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
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Create a set to efficiently check if a word exists in the wordList
        set<string> st(wordList.begin(), wordList.end());
        
        // Create a queue to perform breadth-first search
        queue<pair<string, int>> q;
        
        // Push the start word and its step (distance) into the queue
        q.push({startWord, 1});

        //Remove it from the set
        st.erase(startWord);
        
        while (!q.empty())
        {
            // Get the current word from the front of the queue
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            // If the current word matches the target word, return the step
            if (word == targetWord)
            {
                return step;
            }
            
            // Try all possible one-letter substitutions in the current word
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                
                // Iterate through each lowercase letter from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    // Substitute the character at position i with ch
                    word[i] = ch;
                    
                    // Check if the modified word exists in the wordList
                    if (st.find(word) != st.end())
                    {
                        // If found, remove it from the set to avoid revisiting
                        st.erase(word);
                        
                        // Push the modified word and increment the step into the queue
                        q.push({word, step + 1});
                    }
                }
                
                // Restore the original character at position i for further iterations
                word[i] = original;
            }
        }
        
        // If the target word is not reachable, return 0
        return 0;
    }
};

int main()
{
    return 0;
}