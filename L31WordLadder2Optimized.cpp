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
    // An unordered map to store the minimum distance from beginWord to each word.
    unordered_map<string, int> mp;
    // A vector of vectors to store the resulting transformation sequences.
    vector<vector<string>> ans;

private:
    // Depth-first search (DFS) function to construct transformation sequences.
    void dfs(string &word, vector<string> &sequence, string &beginWord)
    {
        if (word == beginWord)
        {
            // If we reach the beginWord, reverse the sequence and add it to the results.
            reverse(sequence.begin(), sequence.end());
            ans.push_back(sequence);
            reverse(sequence.begin(), sequence.end()); // Reverse it back for further exploration.
            return;
        }
        int size = word.size();
        int steps = mp[word];
        for (int i = 0; i < size; i++)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    sequence.push_back(word);
                    dfs(word, sequence, beginWord); // Continue exploring with the new word.
                    sequence.pop_back();            // Backtrack
                }
                word[i] = original; // Restore the original character.
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // Convert wordList to an unordered set for faster lookup.
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int size = beginWord.size();
        mp[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if (word == endWord)
            {
                break; // If we reach the endWord, stop the BFS.
            }
            for (int i = 0; i < size; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        st.erase(word);
                        q.push(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original; // Restore the original character.
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> sequence(1, endWord);
            dfs(endWord, sequence, beginWord);
        }

        return ans; // Return the resulting transformation sequences.
    }
};

int main()
{
    return 0;
}