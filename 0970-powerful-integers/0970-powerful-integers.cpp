class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> x_value;
        vector<int> y_value;

        unordered_set<int> st;
        int x1 = 1;
        int y1 = 1;
        while (x1 <= bound)

        {
            x_value.push_back(x1);
            if(x==1) break;
            x1 = x1 * x;
        }
        while (y1 <= bound) {
            y_value.push_back(y1);
            if(y==1) break;
            y1 = y1 * y;
        }
       
        // int start = 2;
        for (int i = 0; i < x_value.size(); i++) {
            for (int j = 0; j < y_value.size(); j++) {
                int sum = x_value[i] + y_value[j];
                if (sum <= bound) {
                    // ans.push_back(sum);
                    st.insert(sum);
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};