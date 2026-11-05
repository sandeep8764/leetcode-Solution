class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        //  priority_queue<pair<int, int>> maxheap;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                mp[nums[i]]++;
                // maxheap.push({mp.second,mp.first});
            }
            
        }
        // now create a max -heap 
        priority_queue<pair<int, int>> maxheap;
        for(auto &pair:mp)
        {
            maxheap.push({pair.second,-pair.first});


        }
        if(!maxheap.empty())
        {
            return -maxheap.top().second;
        }
        else return -1;
        
        
    }
};