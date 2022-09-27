    
    int f(int i, string &s, int n, vector<int>&dp) {
        if(i<0) return 1;
        if(dp[i]!=-1) 
            return dp[i];
        int c=0,c1=0;
        if(s[i]!='0') c=f(i-1,s,n,dp);
        if(i-1>=0 && s[i-1]!='0') {
            if(s[i-1]<'3'&&s[i-1]!='2') c1=f(i-2,s,n,dp);
            else if(s[i-1]=='2'&&s[i]<'7') c1=f(i-2,s,n,dp);
        }
        return dp[i]=c+c1;
    }
    
    int numDecodings(string &s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        //return f(n-1, s, n, dp);
        
        dp[0]=1;
        
        for(int i=1;i<n+1;i++)
        {
            int c=0,c1=0;
            
            if(s[i-1]!='0') 
                c=dp[i-1];
            
            if(i-2>=0 && s[i-2]!='0') 
            {
                if(s[i-2]<'3'&&s[i-2]!='2') 
                    c1=dp[i-2];
                else if(s[i-2]=='2'&&s[i-1]<'7') 
                    c1=dp[i-2];
            }
            
            dp[i]=c+c1;
        }
        
        return dp[n];
    }
