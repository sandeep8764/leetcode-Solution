class Solution {
public:
    int compress(vector<char>& chars) {
        int write=0;
        int i=0;
        while(i<chars.size())
        {
            char currentchar=chars[i];
            int count=0;

            while(i<chars.size() && chars[i]==currentchar)
            {
                currentchar=chars[i];
                count++;
                i++;
            }
            chars[write++]=currentchar;
            if(count>1)
            {
                string countstr=to_string(count);
                for(char c:countstr)
                {
                    chars[write++]=c;
                }
            }
        }
        return write;
    }
};