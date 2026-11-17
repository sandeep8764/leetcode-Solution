class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // for this types of problem are 5 method 
        // method 01 sorting approach O(n logn)
        // visisted arrays approach o(n) space O(n)
        // cycle sort o(n)
        // negative elmts o(n)
        // floyd cycle decttion O(n)
        
        // METHOD 01 USING THE SORTING OR NAIVE ALGORITHM 
         sort(nums.begin(),nums.end());
         // after the sorting 0 1 3
         for(int i=1;i<nums.size();i++)
         {
            if (nums[i]!=nums[i-1]+1)return nums[i-1]+1;
            
            
         }
         if(nums[0]!=0) return 0;
         return nums.size();
    }
};