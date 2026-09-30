class Solution {
public:
    int maxDepth(string s) {
        // string s is given now we have to determine the maximum depth of thr string 
        int n=s.size();
        int ans=0;
        stack<char> st;
       
        for(char c:s)
        {
            if(c=='(')
            {
                st.push(c);
                ans=max(ans,(int)st.size()); //here why we use int for the conversion of unsigned to signed interger 
            }
            else if(c==')')
            {
                st.pop();
            }
        }
        // int curr_depth=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         curr_depth++;
        //         ans=max(ans,curr_depth);
        //     }
        //     else if(s[i]==')')
        //     {
        //         curr_depth--;
        //     }
        // }
       
        
        return ans;

        
    }
};