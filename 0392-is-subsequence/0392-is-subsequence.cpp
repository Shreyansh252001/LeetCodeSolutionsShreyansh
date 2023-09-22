class Solution {
public:
    vector<vector<int>> dp;
    
    int issub(string s,string t,int i,int j)
    {
        if(i==0)
            return 1;
        
        if(j==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]==t[j-1])
        {
            return dp[i][j]=issub(s,t,i-1,j-1);
        }
        
        return dp[i][j]= issub(s,t,i,j-1) ;
    }
    
    bool isSubsequence(string s, string t) 
    {
        int n=s.size(),m=t.size();
            
        if(!n)
            return 1;
        if(!m)
            return 0;
        dp.resize(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        
        for(int j=0;j<m;j++)
            dp[0][j]=0;
        
        dp[0][0]=1;
        
        return issub(s,t,n,m);
    }
};