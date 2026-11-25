class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& op) {

        int n = nums.size();
        int n2 = op.size();

        // map for the nums

        unordered_map<int, int> mp;

            for (int i = 0; i < n; i++) {
            mp[nums[i]]=i;
        }
        for (int i = 0; i < n2; i++) {
            int oldval=op[i][0];
            int newval=op[i][1];
            if(mp.find(oldval)!=mp.end())
            {
                int idx = mp[oldval];
                nums[idx] = newval;   // Update the value in the array
                mp[newval] = idx;     // Update the map with the new value's index
                mp.erase(oldval);     // Remove the old 
            }
        }
       return nums;
    }
};