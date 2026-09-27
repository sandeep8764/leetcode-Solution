class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string current = "";

        for (char c : s) {

            // Step 1: Opening bracket
            if (c == '(') {

                // Save the previous string
                st.push(current);

                // Start a new level
                current = "";
            }

            // Step 2: Closing bracket
            else if (c == ')') {

                // Reverse the current level
                reverse(current.begin(), current.end());

                // Get the previous level
                string previous = st.top();
                st.pop();

                // Combine previous + reversed current
                current = previous + current;
            }

            // Step 3: Normal character
            else {

                // Add character to current string
                current += c;
            }
        }

        return current;
    }
};