class Solution {
public:
    int scoreOfParentheses(string s) {
        // ()-> score1
        // (A) → 2 × score(A)
        // AB → score(A) + score(B)
        int score=0;
        int depth=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                depth++;
            }
            else
            {
                depth--;
                
                if(s[i-1]=='(')
                {
                    
                    score+=(1<<depth) ;// left shift concept 

                }
            }
        }
        return score;
    }
};