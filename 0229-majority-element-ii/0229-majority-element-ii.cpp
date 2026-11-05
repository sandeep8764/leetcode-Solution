class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        // in this i want to sto re the frequency and it sindex and after the inusing proirty queue check the frequecny based on max heap 
        vector<int> ans;
        int k=n/3;
        for(auto &it:mp)
        {
            if(it.second>k)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};