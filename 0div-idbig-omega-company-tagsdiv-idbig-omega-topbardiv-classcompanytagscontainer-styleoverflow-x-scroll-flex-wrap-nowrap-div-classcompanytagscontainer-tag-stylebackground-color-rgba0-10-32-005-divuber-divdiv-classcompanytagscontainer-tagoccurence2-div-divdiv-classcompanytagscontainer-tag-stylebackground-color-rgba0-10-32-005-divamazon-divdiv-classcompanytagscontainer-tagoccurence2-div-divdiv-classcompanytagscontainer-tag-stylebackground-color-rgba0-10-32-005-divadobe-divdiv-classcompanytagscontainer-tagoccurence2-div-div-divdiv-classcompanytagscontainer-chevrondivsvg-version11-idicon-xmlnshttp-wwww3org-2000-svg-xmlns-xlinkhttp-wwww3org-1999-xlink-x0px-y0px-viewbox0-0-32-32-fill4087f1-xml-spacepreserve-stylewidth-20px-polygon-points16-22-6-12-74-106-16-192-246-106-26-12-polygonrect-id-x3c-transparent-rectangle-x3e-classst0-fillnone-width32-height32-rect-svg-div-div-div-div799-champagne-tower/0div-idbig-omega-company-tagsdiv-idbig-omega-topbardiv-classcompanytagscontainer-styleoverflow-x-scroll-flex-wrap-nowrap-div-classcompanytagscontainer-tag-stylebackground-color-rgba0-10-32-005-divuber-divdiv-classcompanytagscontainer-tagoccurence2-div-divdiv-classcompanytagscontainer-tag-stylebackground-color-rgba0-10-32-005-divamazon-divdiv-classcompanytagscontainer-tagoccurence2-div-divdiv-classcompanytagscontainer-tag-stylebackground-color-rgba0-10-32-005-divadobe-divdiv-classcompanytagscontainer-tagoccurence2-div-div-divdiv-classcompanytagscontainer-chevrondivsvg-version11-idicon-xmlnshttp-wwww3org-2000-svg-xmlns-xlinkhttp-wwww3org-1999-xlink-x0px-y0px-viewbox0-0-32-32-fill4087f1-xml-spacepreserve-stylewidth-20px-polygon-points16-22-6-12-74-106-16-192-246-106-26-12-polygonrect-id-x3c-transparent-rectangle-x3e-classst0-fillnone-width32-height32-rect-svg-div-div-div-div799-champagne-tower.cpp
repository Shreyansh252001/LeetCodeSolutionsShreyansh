class Solution {
public:
    vector<vector<int>> dp;
    
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        double dp[101];
        
       memset(dp,0.0,sizeof(dp));
        
        int i=0;
        
        dp[0]=(double)poured;
        
        for(int row=0;row<query_row;row++)
        {
            int ans=dp[row]/2;

            for(int j=row;j>=0;j--)
            {
                if(dp[j]>1)
                {
                    double q=(dp[j]-1)/2;
                    dp[j]=q;
                    dp[j+1]+=q;
                }
                else
                {
                    dp[j]=0;
                }
            }
        }
        
        return min(dp[query_glass],1.0);
    }
};