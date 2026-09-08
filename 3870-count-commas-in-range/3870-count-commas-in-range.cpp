class Solution {
public:
    int countCommas(int n) {
        
        long long totalCommas=0;
        long long start=1000;
        if(n>=start)
        {
            totalCommas+=(n-start+1);
            start*=1000;
        }
        return totalCommas;
    }
};