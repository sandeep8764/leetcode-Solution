class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // Here We have to return ann vector arrays of binary numbers 
        // basically here seq is valid parenthesis string 
        // make a seq which have the minimum result (like (max(A,B)))
        int n=seq.size();
        vector<int> result(n);
        int depth=0;
        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                result[i]=depth%2;// ternary operator 
                depth++;
            }
            else
            {
                depth--;
                result[i]=depth%2;
                // depth--;
            }


        }
        return result;
        
    }
};