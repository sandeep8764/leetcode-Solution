class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0); // but it would take the extra space 
        for(int x:nums)
        {
            if(visited[x]) return x;
            else visited[x]=1;
        }
        return -1;
        
    }
};