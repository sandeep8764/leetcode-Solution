class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // method 01 using hashmap or hashtable for lookuap and increase the
        // frequency

        // step 01 first store all the words in hashmap with frequency
        // then using priority Queue select top k elemnts
        int n=words.size();
        struct Compare {
    bool operator()(pair<string, int>& a,
                    pair<string, int>& b) {

        if (a.second == b.second) {
            return a.first > b.first;
        }

        return a.second < b.second;
    }
};

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[words[i]]++;
        }

        // maxheap create
        priority_queue<pair<string, int>,
               vector<pair<string, int>>,
               Compare> maxheap;
        for (auto ch : mp) {
            

            maxheap.push({ch.first,ch.second});
        }
        vector<string> ans;
        while (k-- > 0 && !maxheap.empty()) {
            
            
            ans.push_back(maxheap.top().first);
            maxheap.pop();
        }
        return ans;
    }
};