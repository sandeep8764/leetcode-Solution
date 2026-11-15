class Solution {
public:
// method 03 cyccle sort approach 
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]!=i+1)
            {
                // int x=nums[i];
                 int correctIndex = nums[i] - 1;

                // Duplicate found
                if (nums[i] == nums[correctIndex]) {
                    return nums[i];
                }

                // Place element at correct position
                swap(nums[i], nums[correctIndex]);
            }
            else i++;
        }
        return -1;
        
    }
};