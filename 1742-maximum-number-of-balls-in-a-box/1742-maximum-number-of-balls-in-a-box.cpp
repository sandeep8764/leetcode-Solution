class Solution {
public:
// helper function for the number to digits conversion
int  solve(int n)
{
    int digit_sum=0;
    while(n>0)
    {
        digit_sum+=n%10;
        n=n/10;
    }
    return digit_sum;
}
    int countBalls(int lt, int ht) {
        int n=ht-lt+1;
        // numbe of balls are n 
        // starting from lowlimit to HighLimit 
        // hashmap and priority easily solve thsi problem 
        
        unordered_map<int,int> mp;
        for(int i=lt;i<=ht;i++)
        {
          int value=solve(i);
          mp[value]++;
        }
        priority_queue<pair<int, int>> maxheap;
        for(auto it:mp)
        {
            maxheap.push({it.second, it.first});
        }
        return maxheap.top().first;
        
    }
};