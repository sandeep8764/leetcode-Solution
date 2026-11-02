class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // so we hav eto find th elargest track of lements 
        int n=nums.size();
        
        // Max Heap with custom comparator
        auto cmp = [](string a, string b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        };

        priority_queue<string, vector<string>, decltype(cmp)> maxheap(cmp);
        
        for(int i=0;i<n;i++)
        {
            
            maxheap.push(nums[i]);
            
        }
       
        for(int i=0;i<k-1;i++)
        {
             
             maxheap.pop();
        }
        return maxheap.top();
        
    }
};