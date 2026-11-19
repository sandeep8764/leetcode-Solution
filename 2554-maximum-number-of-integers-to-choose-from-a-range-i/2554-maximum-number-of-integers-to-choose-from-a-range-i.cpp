class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        // method 01  create the vector space of size n
        vector<int> isbanned(n+1,false);
        
        for (int x : banned) {
            
           if(x<=n)
           {
            isbanned[x]=true;

           }
        }
        int count=0;
        int current_sum=0;
        for(int i=1;i<=n;i++)
        {
            if(!isbanned[i])
            {
                if(current_sum+i>maxSum)
                {
                    break;
                    
                }
                
                current_sum+=i;
                    count++;
            }
        }
        
        return count;
    }
};