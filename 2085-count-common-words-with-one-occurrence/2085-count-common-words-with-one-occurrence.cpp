class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size();
        int n2 = words2.size();
        int count = 0;

        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

        // Count frequencies in words1
        for(int i = 0; i < words1.size(); i++) {
            mp1[words1[i]]++;
        }

        // Count frequencies in words2
        for(int i = 0; i < words2.size(); i++) {
            mp2[words2[i]]++;
        }
        // Check words occurring exactly once in both
        for(auto it : mp1) {

            if(it.second == 1 &&
               mp2.count(it.first) &&
               mp2[it.first] == 1) {

                count++;
            }
        }
        return count;
    }
};