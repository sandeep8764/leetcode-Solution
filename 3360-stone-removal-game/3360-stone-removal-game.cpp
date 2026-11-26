class Solution {
public:
    bool solve(int n,int start) {
        if(n<start) return false;
        return !solve(n-start,start-1);
    }
    bool canAliceWin(int n) { 
        return solve(n,10);}
};