class Solution {
public:
    string removeOuterParentheses(string s) {
        // Here valid parenthesis is GIven 
        // Remove the outermost parenthesis
        // Final Answer is String 

        //  Step01 to tore the final string 
        
        int balance=0;
        string ans="";
        string current="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                balance++;
                current=current+"(";
            }
            else
            {
                balance--;
                current=current+")";
            }
            if(balance==0)
            {
                int n=current.length();
                ans=ans+current.substr(1,n-2);
                current="";

            }
        }
        return ans;
    }
};