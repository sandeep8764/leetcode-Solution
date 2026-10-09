class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int insert=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                open++;

            }
            else
            {
                if(i+1<s.length() && s[i+1]==')')
                {
                    i++;

                }
                else
                {
                    insert++;
                }
                if(open>0)
                {
                    open--;
                }
                else
                {
                    insert++;
                }
            }
        }
        return insert+2*open;
        
    }
};