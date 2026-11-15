class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // we have to find the maximum diff in increasing elemnts
        int max_diff = -1;
        int i = 0;
        int j = 1;
        
        while ( j < nums.size()) {
            int diff = nums[j] - nums[i];
            if (diff > 0) {
                max_diff = max(max_diff, diff);
                
            } 
            if(diff<0)
            {
                i=j;
            }
            j++;
        }
        return max_diff;
    }
};