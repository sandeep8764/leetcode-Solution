class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();

        // minimum Distance store karna hai means min-heap banane padenge
        // pair store karenge (dist, index)
        // pair<int, int>
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minheap;

        for (int i = 0; i < n; i++) {
            int px = points[i][0];
            int py = points[i][1];

            if (px == x || py == y) {
                int dist = abs(px - x) + abs(py - y);
                minheap.push({dist, i});
            }
        }

        if (minheap.empty())
            return -1;

        return minheap.top().second;
    }
};