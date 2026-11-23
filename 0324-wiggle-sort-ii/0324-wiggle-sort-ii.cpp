class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // int n = nums.size();
        // int i = 0;
        // int j = n - 1;
        // sort(nums.begin(), nums.end());
        // vector<int> ans;

        // while (i < j) {
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[j]);
        //     i++;
        //     j--;
            
        // }
        // if (i == j) {
        //     ans.push_back(nums[i]);
        // }
        // return ans;
       vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int mid=(n-1)/2;
        int right=n-1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                nums[i]=temp[mid--];
            }
            else 
            {
                nums[i]=temp[right--];
            }
        }
    }
};