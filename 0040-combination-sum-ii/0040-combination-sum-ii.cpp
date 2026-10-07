class Solution {
public: 
// Helper Function 
void solve(vector<int>& candidates, int target,int i,vector<vector<int>> &ans,vector<int> &current )
{
    // base case condition 01 
    if(target==0)
    {
        ans.push_back(current);
        return ;
    }
    // base case condition 02
    if(i>=candidates.size() || target<0)
    {
        return ;
    } 
   for(int j=i;j<candidates.size();j++)
   {
        // Skip duplicate values at the same recursion level
            if (j > i && candidates[j] == candidates[j - 1])
            {
                continue;
            }

            // Since array is sorted
            if (candidates[j] > target)
            {
                break;
            }

     // take 
    current.push_back(candidates[j]);
    solve(candidates,target-candidates[j],j+1,ans,current);
    current.pop_back();

    

   }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Final answr is in 2 D vector 
        vector<vector<int>> ans;
        vector<int> current; // to store the current values 
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,ans,current);
        return ans;

        
    }
};