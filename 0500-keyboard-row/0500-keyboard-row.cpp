class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Here first We create HashMap for the All rows to Store rhe character 
        // now from the input words start searching in th hasmap 
        // if all character are foun d in the same rows the push to resultant vector 

        unordered_map<char , int> Row;

        string first="qwertyuiop";
        string second="asdfghjkl";
        string third="zxcvbnm";

        for(char c:first) Row[c]=1;
        for(char c:second) Row[c]=2;
        for(char c:third) Row[c]=3;

        vector<string> result; // To store the final answer
        for(string word:words)
        {
            int wordrow = Row[tolower(word[0])];
             
            bool valid=true;
            for(char c:word)
            {
                c = tolower(c); 
                if(Row[c]!=wordrow)
                {
                    
                    valid=false;
                    break;
                }
                
            }
            if(valid)
            {
                result.push_back(word);
            }
        }
        return result;


    }
};