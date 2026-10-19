class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // after sorting (n log n)
        sort(nums.begin(), nums.end());
        // for the Store the indices
        vector<int> ans;
        // now use Binary search ( n log n)
        int left = 0;
        int right = nums.size() - 1;
        int first=-1;

        while (left <=right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                // ans.push_back(mid);
                first=mid;
                right=mid-1;
                
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(first!=-1)
        {
            while(first<nums.size()&& nums[first]==target)
            {
                ans.push_back(first);
                first++;
            }
        }
        return ans;
    }
};