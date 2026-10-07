class Solution {
public:

    void solve(string &s,
               int index,
               int leftRemove,
               int rightRemove,
               int open,
               int close,
               string &current,
               unordered_set<string> &ans)
    {
        // Base case
        if(index == s.length())
        {
            if(leftRemove == 0 &&
               rightRemove == 0 &&
               open == 
               close )
            {
                ans.insert(current);
            }

            return;
        }

        char ch = s[index];

        // --------------------------------
        // Case 1: '('
        // --------------------------------
        if(ch == '(')
        {
            // Remove '('
            if(leftRemove > 0)
            {
                solve(s, index + 1,
                      leftRemove - 1,
                      rightRemove,
                      open,
                      close,
                      current,
                      ans);
            }

            // Keep '('
            current.push_back('(');

            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  open + 1,
                  close,
                  current,
                  ans);

            current.pop_back();
        }

        // --------------------------------
        // Case 2: ')'
        // --------------------------------
        else if(ch == ')')
        {
            // Remove ')'
            if(rightRemove > 0)
            {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove - 1,
                      open,
                      close,
                      current,
                      ans);
            }

            // Keep ')' only if '(' exists
            if(open > close)
            {
                current.push_back(')');

                solve(s, index + 1,
                      leftRemove,
                      rightRemove,
                      open,
                      close + 1,
                      current,
                      ans);

                current.pop_back();
            }
        }

        // --------------------------------
        // Case 3: Normal character
        // --------------------------------
        else
        {
            current.push_back(ch);

            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  open,
                  close,
                  current,
                  ans);

            current.pop_back();
        }
    }


    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals
        for(char ch : s)
        {
            if(ch == '(')
            {
                leftRemove++;
            }
            else if(ch == ')')
            {
                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        unordered_set<string> ans;
        string current;

        solve(s,
              0,
              leftRemove,
              rightRemove,
              0,
              0,
              current,
              ans);

        for(auto &str : ans)
        {
            result.push_back(str);
        }

        return result;
    }
};