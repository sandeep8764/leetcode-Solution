class Solution {
public:
    bool judgeSquareSum(int c) {
        // Final Answer is true and false or boolean 
        // number is given we have to check it is made form square of number 
        int low=0;
        long long  high=sqrt(c);
        while(low<=high)
        {
            long long  product=low*low+high*high;
            if(product==c)
            {
                return true;
            }
            if(product<c) low++;
            else high--;
        }
        return false;
    }
};