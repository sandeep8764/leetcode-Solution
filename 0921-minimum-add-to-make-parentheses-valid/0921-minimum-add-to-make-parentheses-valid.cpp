class Solution {
public:
    int minAddToMakeValid(string s) {
        // zfinal required answer is int 
        int open =0;
        int close =0;
        int balance=0;
        int additions=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                balance++;
            }
            else 
            {
                if(balance>0)
                {
                    balance--;

                }
                else 
                {
                    additions++;
                }
                
            }
        }
        return additions+balance;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         open++;
        //     }
        //     else
        //     {
        //         close++;
        //     }
        // }
        // int diff=abs(open-close);
        // return diff;
        
    }
};