class Solution {
public:
    bool canBeValid(string s, string locked) {
        // stack<char>st;
        // if(s.length()<2 || locked.length()<2)
        // {
        //     return false;

        // }
        // return true;
        // Here locked[i]==0 s[i] can be change 
        // here locked[i]==1 s[i] cannot be change 
        // length must be ec=ven then it is possible 

        // First case Would be 
        if(s.length()%2!=0)
        {
            return false;
        }
        int balance =0;
        for(int i=0;i<s.length();i++)
        {
           if( locked[i]=='0')
           {
            // treat (
            balance++;
           }
           else if(s[i]=='(')
           {
            balance++;
           }
           else
           {
            balance--;
           }
           if(balance<0)
           {
            return false;
           }
            
        }
// Right to left 
        balance=0; // reset the balance equal to zero 
        for(int i=s.length()-1;i>0;i--)
        {
            if(locked[i]=='0')
            {
                // treat )
                balance++;

            }
            else if(s[i]==')')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            if(balance<0)
            {
                return false;
            }
        }
        return true;
        
    }
};