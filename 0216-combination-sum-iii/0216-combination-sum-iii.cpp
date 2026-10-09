class Solution {
public:
void solve(int start,int k ,int n ,vector<vector<int>> &ans ,vector<int> &current)
{
    if(k==0)
    {
        if(n==0)
        {
            ans.push_back(current);
        }
    }
    for(int i =start;i<=9;i++)
    {
        if(i>n)
        {
            break;
        }
        current.push_back(i);
        solve(i+1,k-1,n-i,ans,current);
        // after it each steps fails in reccursive callling POP back 
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current ;
        solve(1,k,n,ans,current);
        return ans;
    }
};