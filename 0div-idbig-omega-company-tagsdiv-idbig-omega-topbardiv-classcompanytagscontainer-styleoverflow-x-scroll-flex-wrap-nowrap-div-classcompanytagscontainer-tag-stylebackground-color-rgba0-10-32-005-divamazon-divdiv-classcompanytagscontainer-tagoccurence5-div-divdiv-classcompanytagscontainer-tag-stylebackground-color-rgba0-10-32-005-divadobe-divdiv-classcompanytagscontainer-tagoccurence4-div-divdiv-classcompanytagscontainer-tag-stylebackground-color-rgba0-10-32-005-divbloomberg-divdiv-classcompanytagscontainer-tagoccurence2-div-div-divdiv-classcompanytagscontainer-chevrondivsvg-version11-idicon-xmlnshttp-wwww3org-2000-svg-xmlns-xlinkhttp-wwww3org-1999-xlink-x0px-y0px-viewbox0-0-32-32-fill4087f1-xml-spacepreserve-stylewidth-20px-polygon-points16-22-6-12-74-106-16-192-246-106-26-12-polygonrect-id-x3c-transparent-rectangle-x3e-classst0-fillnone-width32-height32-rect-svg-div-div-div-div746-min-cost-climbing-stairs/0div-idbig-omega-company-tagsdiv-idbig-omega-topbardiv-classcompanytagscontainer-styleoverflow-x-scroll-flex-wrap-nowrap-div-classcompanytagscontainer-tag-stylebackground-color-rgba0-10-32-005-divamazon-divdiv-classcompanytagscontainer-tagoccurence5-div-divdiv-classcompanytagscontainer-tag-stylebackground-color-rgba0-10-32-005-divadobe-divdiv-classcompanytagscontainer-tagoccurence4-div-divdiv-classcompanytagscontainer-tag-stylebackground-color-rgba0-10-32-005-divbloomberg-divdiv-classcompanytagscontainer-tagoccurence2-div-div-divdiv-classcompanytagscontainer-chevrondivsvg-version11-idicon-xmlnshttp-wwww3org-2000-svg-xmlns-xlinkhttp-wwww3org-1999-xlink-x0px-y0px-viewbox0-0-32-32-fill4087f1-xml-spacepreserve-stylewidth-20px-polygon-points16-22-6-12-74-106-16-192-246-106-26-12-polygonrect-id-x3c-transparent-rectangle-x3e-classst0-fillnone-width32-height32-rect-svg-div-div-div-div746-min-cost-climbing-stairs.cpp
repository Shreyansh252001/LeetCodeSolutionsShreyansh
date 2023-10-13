class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        
        if(n==1)
            return cost[0];
        
        vector<int> dp(n+1,INT_MAX);
        
        dp[0]=0;
        dp[1]=cost[1];
        
        for(int i=0;i<n-1;i++)
        {
            dp[i+1]=min(dp[i+1],dp[i]+cost[i]);
            dp[i+2]=min(dp[i+2],dp[i]+cost[i+1]);
        }
        
        dp[n]=min(dp[n],dp[n-1]+cost[n-1]);
        
        return min(dp[n],dp[n-1]);
    }
};