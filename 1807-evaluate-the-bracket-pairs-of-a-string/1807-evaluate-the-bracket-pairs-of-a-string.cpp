class Solution {
public:

    string evaluate(string s, vector<vector<string>>& knowledge) {
        // string s is given 
        // 2D matrix is given ->key value pair is given in it 
        // if key value pair is found then replace it with the value else ?
        // output like ->"bobistwoyearsold"
        // if bracket found then replace it with the values from matrix

        // stepo1 
        //string result="" // empty string 
        unordered_map<string ,string> mp;
    for(const auto& pair:knowledge)
    {
        mp[pair[0]]=pair[1];
    }
    string result="";
    string key="";
    bool insidebracket=false;

    for(char c:s)
    {
        if(c=='(')
        {
            insidebracket=true;
            key="";
        }
        else if(c==')')
        {
            insidebracket=false;
            if(mp.count(key))
            {
                result+=mp[key];
            }
            else
            {
                result+='?';
            }
        }
            else {
                    if (insidebracket) 
                    {
                        key += c; 
                    } else 
                    
                    {
                        result += c; 
                    }
                }
        
    }
    return result;
    }

        
    
};