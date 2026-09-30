class Solution {
public:
    int maxDepth(string s) {
        // string s is given now we have to determine the maximum depth of thr string 
        int n=s.size();
        int ans=0;
        // stack<char>st;
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         st.push(s[i]);
        //     }
        //     else if(s[i]==')')
        //     {
        //         st.pop();
        //         ans++;
        //     }
        //     else
        //     {
        //         continue;
        //     }
        // }
        int curr_depth=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                curr_depth++;
                ans=max(ans,curr_depth);
            }
            else if(s[i]==')')
            {
                curr_depth--;
            }
        }
       
        
        return ans;

        
    }
};