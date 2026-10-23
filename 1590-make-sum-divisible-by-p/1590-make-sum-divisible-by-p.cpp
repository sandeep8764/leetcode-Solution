class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Given arrays of Positive interger 
        int n=nums.size();// size of the arrays 
        // remove the smallest sub-Arrays may be Empty so remaining sum is Divisble by k 
        int total=0;
        for(int x:nums)
        {
           total=(total+x)%p;
        }
        if(total%p==0) return 0;

        //int rem=total%p;// it gives the reaminder to remove it form the arrays 
        unordered_map<int, int> mp;
        mp[0]=-1;
        int prefix=0;
        int ans=n;
        int rem=total;
        for(int i=0;i<n;i++)
        {
            prefix=(prefix+nums[i])%p;
            int need=(prefix-rem+p)%p;
            if(mp.find(need)!=mp.end())
            {
                ans=min(ans,i-mp[need]);
            }
            mp[prefix] = i;
        }
        return ans==n?-1:ans;
        // Prefix Sum + Modulo + unordered_map

        
        
    }
};