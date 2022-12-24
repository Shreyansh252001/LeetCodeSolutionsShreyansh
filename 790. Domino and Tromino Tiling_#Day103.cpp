class Solution {
public:
    const int mod=1e9+7;
    int numTilings(int n) 
    {
      
        
        if(n==1||n==2)
            return n;
        
        vector<long int> dp(n+1,0);
        
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
      //  dp[3]=5;
        
        for(int i=4;i<=n;i++)
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        
        return dp[n]%mod;
    }
};
