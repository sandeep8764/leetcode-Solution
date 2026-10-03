class Solution {
public:
// here Jobs Are Dependent 
// Each days Atleast on job is to be complete 
// difficulty of job is (maxof job done on that days )
// calculate the mindifficulty
int t[301][11];
     int solve(vector<int>&jd,int n,int d,int idx)
     {
        // base case Condition day==1
        if(d==1)
        {
            int maxD=0;
            for(int i=idx;i<n;i++)
            {
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        if(t[idx][d]!=-1)
        {
            return t[idx][d];
        }
        int maxD=0;
        int finalresult=INT_MAX;
        for(int i=idx;i<=n-d;i++)
        {
            maxD=max(maxD,jd[i]);
            int result=maxD+solve(jd,n,d-1,i+1);
            finalresult=min(finalresult,result);
        }
        return t[idx][d]=finalresult;

     }

    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size(); // Arrays Length
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
        return solve(jd,n,d,0);

        
    }
};