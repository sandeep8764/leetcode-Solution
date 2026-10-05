class Solution {
public:
    int scoreOfParentheses(string s) {
        // ()-> score1
        // (A) → 2 × score(A)
        // AB → score(A) + score(B)
        int score=0;
        stack<int> st;
        st.push(0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(0);
            }
            else
            {
                 int inner_score=st.top();
                 st.pop();
                 if(inner_score==0)
                 {
                    score=1;
                 }
                 else
                 {
                    score=2*inner_score;
                 }
                 st.top()+=score;
            }
        }
        return st.top();
    }
};