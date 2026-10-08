class Solution {
public:
// Here WE Define the Reccursive Function 
double solve(double  x, long long  n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 1/solve(x,-n);
     

    }
    double half=solve(x,n/2);
    if(n%2==0)
    {
        return half *half;
    }
    else
    {
        return x*half*half;
    }
}
    double myPow(double x, int n) {
        // Final Answer may be Decimal types so we need double type 
        
         return solve(x,(long long ) n);
        
        
    }
};