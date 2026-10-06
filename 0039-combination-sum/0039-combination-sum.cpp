class Solution {
public: 
// Helper function 
void solve(vector<int>& candidates, int target,int index,vector<vector<int>> &ans,vector<int> current)
{
    // Base Case Condition 
    if(target==0)
    {
        ans.push_back(current);
        return ;
    }
    if(index==candidates.size())
    {
        return ;
    }
    // choics 01
    if(candidates[index]<=target)
    {
        current.push_back(candidates[index]);
        solve(candidates,
        target-candidates[index],
        index,
        ans,
        current);


         // undo
        current.pop_back();
    }
     solve(candidates,target,index+1,ans,current);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Final Answer is 2D vector 
        vector<vector<int>> ans; // 2D vector To store ans 
        vector<int> current; // to tore the current solution  
        solve(candidates, target, 0, ans,current);
        return ans;

    }
};