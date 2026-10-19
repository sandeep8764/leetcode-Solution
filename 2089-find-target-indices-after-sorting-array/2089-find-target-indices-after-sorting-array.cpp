class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // after sorting (n log n)
        sort(nums.begin(), nums.end());
        // for the Store the indices
        vector<int> ans;
        // now use Binary search ( n log n)
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target) ans.push_back(i);
        }
        return ans;
    }
};