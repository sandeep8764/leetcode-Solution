class Solution {
public:
    int  t[101][101];
    bool solve(string & s ,int idx, int balance)
    {
        if(balance<0)
        {
            return false;

        }
        if(idx==s.length())
        {
            return balance==0;
        }
        if(t[idx][balance] != -1)
            return t[idx][balance];
        if(s[idx]=='(')
        {
            return t[idx][balance]=solve(s,idx+1,balance+1);
        }
        if(s[idx]==')')
        {
            return t[idx][balance]=solve(s,idx+1,balance-1);
        }
        return t[idx][balance]=solve(s,idx+1,balance+1) || solve(s,idx+1,balance-1) || solve(s, idx+1, balance);
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
         return solve(s,0,0);
        

        
    }
};