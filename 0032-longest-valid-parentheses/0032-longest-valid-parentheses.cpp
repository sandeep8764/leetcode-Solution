class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0;
        int right = 0;
        int ans = 0;

        // Left -> Right
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
                right++;

            if(left == right)
            {
                ans = max(ans, 2 * right);
            }
            else if(right > left)
            {
                left = 0;
                right = 0;
            }
        }

        // Reset
        left = 0;
        right = 0;

        // Right -> Left
        for(int i = (int)s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
                right++;
            else
                left++;

            if(left == right)
            {
                ans = max(ans, 2 * left);
            }
            else if(left > right)
            {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};