class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        //   Special Elemnts are if(n%1)==0
        int n=nums.size();// Size of the arrays 
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=nums[i-1]*nums[i-1];
            }
        }
        return ans;
    }
};