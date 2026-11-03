class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int largest=INT_MIN;
        int sum=0;
        for(int x:nums)
        {
            largest=max(largest,x);
            sum+=x;

        }
        return largest*n-sum;
        
    }
};