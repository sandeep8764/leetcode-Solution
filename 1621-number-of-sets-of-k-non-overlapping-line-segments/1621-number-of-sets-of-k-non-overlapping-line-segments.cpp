class Solution {
public:
int MOD=1e9+7;
    int memo[1001][1001][2];

int solve(int i,int k,int drawing,int n)
{
    // Base Case COnditon 
    if(k==0) return 1;
    if(i>=n) return 0;
    if(memo[i][k][drawing]!=-1) return memo[i][k][drawing];

    long long count=0;
    if(drawing==0)
    {
        count=(count+solve(i+1,k,0,n))%MOD;

        count=(count+solve(i+1,k,1,n))%MOD;
    }
    else
    {
        count=(count+solve(i+1,k,1,n))%MOD;
        count=(count+solve(i,k-1,0,n))%MOD;
    }
    return memo[i][k][drawing]=count;
    
    
    

}
    int numberOfSets(int n, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(0,k,0,n);
        

        
    }
};