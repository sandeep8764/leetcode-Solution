class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // first create the hashmap for the store the elements that rae allowd
        // to use

        unordered_map<char, int> mp;
        for (int i = 0; i < allowed.size(); i++) {
            mp[allowed[i]]++;
        }
        // words of the arrys is given
        int n = words.size();
        // now for each string in words that ra emade from char in alloed that
        // are store in map

        // now use helper function that to find it is found int or not
        //  bool charfound(char)
        //  {
        //     if (mp.find(ch)!=mp.end()) return true;
        //     else return false;

        //  }
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;

            for (int j = 0; j < words[i].size(); j++) {
                if (mp.find(words[i][j]) == mp.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag==true) count++;
        }
        return count;
    }
};