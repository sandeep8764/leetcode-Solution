class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // by deafulayt Question Goes towards the max-heap
        //max_Heao with pairs(value, index) 
        priority_queue<pair<int, int>>maxheap;
        for (int i = 0; i < nums.size(); i++) {
            maxheap.push({nums[i], i});
        }
        vector<pair<int, int>> num;
        for (int i = 0; i < k; i++) {
        num.push_back(maxheap.top()) ;
            maxheap.pop();
        }
        // Restore original order with  custorm comparator 
        sort(num.begin(), num.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> ans;
        for (auto& x : num) {
            ans.push_back(x.first);
        }
        return ans;
    }
};