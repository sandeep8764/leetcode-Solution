class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        // int i=0;
        // int j=0;
        // int index=-1;
        // while(i<n && j<m)
        // {
        //     if(haystack[i]==needle[j])
        //     {
                
        //         i++;
        //         j++;
        //         if(j==m)
        //         {
        //             index=i-j;
        //         }
        //     }
        //     else if(haystack[i]!=needle[j])
        //     {
        //         i++;
        //         j=0;
        //     }
        // }
        // return index; 
        

        for(int i=0;i<=n-m;i++)
        {
            int j=0;
            while(j<m && haystack[i+j]==needle[j])
            {
                j++;
            }
            if(j==m)
            {
                return i;
            }
        }
        return -1;
    }
};