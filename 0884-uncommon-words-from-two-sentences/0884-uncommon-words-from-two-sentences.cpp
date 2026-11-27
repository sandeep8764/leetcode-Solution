class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();

        // unordered_map<string , int> mp;
        // vector<string> ans;
        // if(n1>n2)
        // {
        //     for(int i=0;i<n1;i++)
        //     {
        //         mp[s1[i]]=i;
        //     }
        //     for(int i=0;i<n2;i++)
        //     {
        //         if(mp.finr(s2[i])!=mp.end())
        //         {
        //             ans.push_back(s2[i]);
        //         }
        //     }

        // }
        // else 
        // {
        //     for(int i=0;i<n2;i++)
        //     {
        //         mp[s2[i]]=i;
        //     }
        //     for(int i=0;i<n1;i++)
        //     {
        //         if(mp.finr(s1[i])!=mp.end())
        //         {
        //             ans.push_back(s1[i]);
        //         }
        //     }

        // }
        // return ans;

        unordered_map<string , int> mp;
        stringstream ss1(s1);

        string word;
        while(ss1>>word)
        {
            mp[word]++;
        }
        stringstream ss2(s2);
        
        //string word;
        while(ss2>>word)
        {
            mp[word]++;
        }
        vector<string> ans;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;

        
    }
};