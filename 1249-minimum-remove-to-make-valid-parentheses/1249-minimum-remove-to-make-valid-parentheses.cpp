class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans=""; // store th result 
       vector<int> st;
        if(s.length()==0)
        {
            return ans;
        }
        int balance=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push_back(i);

            }
            else if(s[i]==')')
            {
               if(!st.empty())
               {
                st.pop_back();
               }
               else
                {
                    s[i]='*';
                }
            }
            
        }
        for(int idx:st)
        {
            s[idx]='*';
        }
        for(char c:s)
        {
            if(c!='*')
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};