class Solution {
public:
    //  for th ecalculation of the mirror number
    int solve(int i) {
        int number = 0;
        int t = i;
        while (t > 0) {
            int rem = t % 10;
            number = number * 10 + rem;
            t = t / 10;
        }
        return number;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> min_hp;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int rev = solve(nums[i]);
            cout<< rev << endl;
            if (mp.find(nums[i]) != mp.end()) {
                int diff = abs(i - mp[nums[i]]);
                min_hp.push(diff);
            }
            
            mp[rev] = i;
        }
        return min_hp.empty() ? -1 : min_hp.top();
    }
};