class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        unordered_map<string , int> mp;

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;// basically count the frequency of each wrods 

        }
      
        // for(auto it:mp)
        // {
        //     if(it.second==1 &&k>0)
        //     {
        //         ans.push_back(it.first);
        //         k--;
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                k--;
                if(k==0) return arr[i];
            }
        }
        return "";
        
    }
};