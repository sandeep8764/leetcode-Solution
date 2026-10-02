class Solution {
public:
    // Helper function (reccursion +BackTrack)
    void backtrack( vector<string> &result, string current,int open,int close, int n)
    {
        // basecase condition 
        if(open==n && close==n)
        {
            result.push_back(current);
            return ;
        }
        if(open<n)
        {
            current.push_back('(');
            backtrack(result,current,open+1,close,n);
            current.pop_back();
           
        }
        if(close<open)
        {
            current.push_back(')');
             backtrack(result,current,open,close+1,n);
             current.pop_back();

            
            // close++;
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // Finally we have to return Vector of the String 
        // n is given 
        // Maximum depth is equal to n 
        // Total brackets Used in it ==2*n
        // base case condition is comes from open==n && close==n
        // reccursion + backtracking 
        // Number of combimation are can be formmed 
        vector<string> result;
        backtrack(result,"",0,0,n);

        return  result;

        
    }
};