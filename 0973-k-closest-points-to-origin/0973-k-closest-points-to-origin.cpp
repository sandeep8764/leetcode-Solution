class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Here we reqired the K closet points so require the min heap 

        priority_queue<
            pair<int, int> ,
            vector<pair<int,int>> ,
            greater<pair<int,int>>
            > minheap;
            // here Declaration of min Heap 

           for(int i=0;i<points.size();i++)
           {
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            minheap.push({dist,i});
           }
            // now finally output is 
            vector<vector<int>> ans;
            while(k-->0 && !minheap.empty())
            {
                int index=minheap.top().second;
                minheap.pop();
                ans.push_back(points[index]);
            }
            return ans;


        
    }
};