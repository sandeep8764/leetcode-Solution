class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> stmap;
        unordered_map<char, char> tsmap;

        for (int i = 0; i < s.length(); i++) {
            char cs = s[i];
            char ct = t[i];
            // if(tsmap.count(cs) && tsmap[cs]!=ct) return false;
            // if(stmap.count(ct) && stmap[ct]!=cs) return false;
            if (stmap.count(cs) && stmap[cs] != ct)
                return false;

            if (tsmap.count(ct) && tsmap[ct] != cs)
                return false;

            stmap[cs] = ct;
            tsmap[ct] = cs;
        }
        return true;
    }
};