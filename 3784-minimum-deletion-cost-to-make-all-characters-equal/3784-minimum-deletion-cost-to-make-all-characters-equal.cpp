class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        // we have to find minimum sum so after character is equal
        // create the unodred map so store its character and its cost

        unordered_map<char, vector<long long >> mp;
        long long  total=0;
        for (int i = 0; i < s.length(); i++) {
            // mp.push({s[i],cost[i]});
            // mp[s[i]]=cost[i]; // or we can use it mp.insert({s[i],cost[i]})
            mp[s[i]].push_back(cost[i]);
            total+=cost[i];
        }
        long long  maxi=0;
        for(auto  it:mp)
        {
            long long sum=0;
            for(auto x:it.second)
            {
                sum+=x;

            }
            maxi=max(maxi,sum);
        }
        return total - maxi;
    }
};