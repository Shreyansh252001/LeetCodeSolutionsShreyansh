 set<string> s1(wordDict.begin(),wordDict.end());
        int n=s.length();
        
        vector<int> dp(n+1);
        
        dp[0]=true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && s1.find(s.substr(j,i-j))!=s1.end())
                {
                    dp[i]=true;
                    break;   
                }
            }
        }
        
        return dp[n];
