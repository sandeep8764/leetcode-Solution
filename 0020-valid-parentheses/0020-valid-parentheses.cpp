class Solution {
public:
    bool isValid(string s) {
        // simle parenthesis Question we use stack here 
        stack<char>st;
        for(char c:s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                st.push(c);
            }
            else
            {
                if(st.size()==0) return false;
               else
               {
                    char Top=st.top(); // only we check this condition if stack is not empty
                         if(c==')' && Top=='(' ||
                         c=='}' && Top=='{' ||
                         c==']' && Top=='[')
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
               }

            }
        }
        if(st.size()!=0) return false;
        return true;
        // basically in this question multiple if else condition is used 
    }
};