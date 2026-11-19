class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // method 01 
        int n=nums.size();
        vector<int> isfound(n+1,false);
        vector<int> ans;

        for(int x:nums)
        {
            if(x<=n)
            {
                isfound[x]=true;

            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!isfound[i])
            {
                ans.push_back(i);
            }

        }
        return ans;
        
    }
};