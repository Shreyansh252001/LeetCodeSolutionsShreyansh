class Solution {
public:
    int integerBreak(int n) 
    {
        if(n<=3)
            return n-1;
        
        vector<int> dp(n+1,0);
        
        //all three initialized according to numbers because after substracting the from the given number if it reaches to 1,2,3 then there is no further spliting required and number returned for multiplication to get answwer will be the same number
        
        dp[3]=3;
        dp[2]=2;
        dp[1]=1;
        
        for(int i=4;i<=n;i++)
        {
            for(int j=2;j<i;j++)
            {
                    dp[i]=max(dp[i],j*dp[i-j]);
            }
        }
        
        return dp[n];
    }
};