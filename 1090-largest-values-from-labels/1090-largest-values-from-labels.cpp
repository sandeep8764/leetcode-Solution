class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int numWanted, int useLimit) {
        unordered_map<int, int> mp;
         priority_queue<pair<int, int>> maxheap;
        int n = values.size();
        for (int i = 0; i < n; i++) {
            maxheap.push({values[i],labels[i]});
            
        }
       
        // first ==values 
        // second==labesl
        
        int sum=0;
        while(numWanted>0 && !maxheap.empty())
        {
            int num=maxheap.top().first;
            int label = maxheap.top().second;
            
            maxheap.pop();
            if(mp[label] < useLimit)
            {
                sum += num;
                mp[label]++;
                numWanted--;
            }
        }
        return sum;
        // now use maxheap for this to use max elemnet and if the its frequnscy
        // its greater that use limit then use its max use limit and if the grat
        // erthen use  elemnst times max elemenst
    }
};