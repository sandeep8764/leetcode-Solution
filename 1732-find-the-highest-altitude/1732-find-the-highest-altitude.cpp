class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> prefix_val(n+1);
        prefix_val[0]=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            prefix_val[i+1]=prefix_val[i]+gain[i];
            ans=max(ans,prefix_val[i+1]);

        }
        return ans;
        
    }
};