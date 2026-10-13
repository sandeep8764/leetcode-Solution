class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
           int smaller=nums[i]-k;
           int larger=nums[i]+k;
           count+=mp[smaller];
           count+=mp[larger];
           mp[nums[i]]++;

        }
        return count;
        
    }
};