class Solution {
public:
    bool checkValidString(string s) {
        // Final result is Boolean 
        // valid Parenthesis 
        // * is treated as  can ( or )

        // Step01 Left to right traversal 
        int minopen=0;
        int maxopen=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                minopen++;
                maxopen++;
            }
            else if(s[i]==')')
            {
                minopen--;
                maxopen--;
            }
            else
            {
                minopen--;
                maxopen++;
            }
            if(minopen<0)
            {
                minopen=0;
            }
            if(maxopen<0)
            {
                return false;

            }
        }
        return minopen==0;
        // return true;
    }
};