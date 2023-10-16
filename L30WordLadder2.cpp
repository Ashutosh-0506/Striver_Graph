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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>>ans;
        queue<vector<string>>q;
        set<string>st(wordList.begin(),wordList.end());
        int level=0;
        vector<string>used;

        q.push({beginWord});
        used.push_back(beginWord);

        while(!q.empty())
        {
            vector<string>temp=q.front();
            q.pop();

            if(temp.size()>level)
            {
                level++;
                for(auto it:used)
                {
                    st.erase(it);
                }
            }

            string word=temp.back();


            //Check
            if(word==endWord)
            {
                //IF ITS THE FIRST SEQUENCE
                if(ans.size()==0)
                {
                    ans.push_back(temp);
                }
                //IF WE HAVE A NEXT SEQUENCE EQUAL TO THE FIRST SEQUENCE LENGTH
                else if(ans[0].size()==temp.size())
                {
                    ans.push_back(temp);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        temp.push_back(word);
                        q.push(temp);
                        used.push_back(word);
                        temp.pop_back();
                    }
                }
                word[i]=original;
            }
            
        }
        return ans;
    }
};
int main()
{
    return 0;
}