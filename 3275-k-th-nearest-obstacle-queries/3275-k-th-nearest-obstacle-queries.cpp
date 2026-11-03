class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        priority_queue<int> maxheap;

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int x = queries[i][0];
            int y = queries[i][1];

            int dist = abs(x) + abs(y);

            maxheap.push(dist);

            if (maxheap.size() > k) {
                maxheap.pop();
            }

            if (maxheap.size() < k) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(maxheap.top());
            }
        }

        return ans;
    }
};