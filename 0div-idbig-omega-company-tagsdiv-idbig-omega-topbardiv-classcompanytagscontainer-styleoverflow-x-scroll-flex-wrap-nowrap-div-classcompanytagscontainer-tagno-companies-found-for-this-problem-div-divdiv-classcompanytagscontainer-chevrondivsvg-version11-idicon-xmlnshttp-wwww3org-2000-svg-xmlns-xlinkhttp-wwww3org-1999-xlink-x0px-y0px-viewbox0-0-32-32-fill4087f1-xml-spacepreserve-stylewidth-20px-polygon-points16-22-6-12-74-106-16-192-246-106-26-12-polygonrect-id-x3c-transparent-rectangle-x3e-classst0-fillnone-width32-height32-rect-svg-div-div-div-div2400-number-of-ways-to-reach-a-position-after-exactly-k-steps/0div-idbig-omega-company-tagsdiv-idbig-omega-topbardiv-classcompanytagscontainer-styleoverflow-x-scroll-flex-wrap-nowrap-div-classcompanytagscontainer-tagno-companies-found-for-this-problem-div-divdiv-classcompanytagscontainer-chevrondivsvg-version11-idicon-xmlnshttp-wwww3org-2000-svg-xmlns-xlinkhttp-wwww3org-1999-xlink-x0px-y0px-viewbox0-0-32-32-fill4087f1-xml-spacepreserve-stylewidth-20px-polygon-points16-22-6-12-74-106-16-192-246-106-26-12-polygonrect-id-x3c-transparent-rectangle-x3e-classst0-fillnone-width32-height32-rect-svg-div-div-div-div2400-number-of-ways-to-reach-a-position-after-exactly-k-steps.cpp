class Solution 
{
public:
    const long int mod=1000000007;
    
    vector<vector<long long int>> dp;
    
    long long int dfs(int s,int e,int k)
    {
        
        if(k==0)
        {
            if(s==e)
                return 1;
            else
                return 0;
        }
        if(k<0)
            return 0;
        
        // if(s<=0 || s>e)
        //     return 0;
        //cout<<s<<" "<<k<<"\n";
        
        if(dp[s+1000][k]!=INT_MAX)
            return dp[s+1000][k];
        
        return dp[s+1000][k]=(dfs(s+1,e,k-1)+dfs(s-1,e,k-1))%mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k)
    {
        dp.resize(3001,vector<long long int>(k+1,INT_MAX));
        
        return dfs(startPos,endPos,k)%mod;
    }
};