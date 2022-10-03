bool isinterleave(string s1,int i,string s2,int j,string res,string s3,int k)
    {
        if(i==s1.length())
        {
            res+=s2.substr(j);
            return res==s3;
        }
        
        if(j==s2.length())
        {
            res+=s1.substr(i);
            return res==s3;
        }
        
        if(dp[i][j]==1||dp[i][j]==0)
            return dp[i][j];
        
        bool ans=false;
        
        if((s3[k]==s1[i] && isinterleave(s1,i+1,s2,j,res+s1[i],s3,k+1)) || (s3[k]==s2[j] && isinterleave(s1,i,s2,j+1,res+s2[j],s3,k+1)))
            dp[i][j]=1;
         else
             dp[i][j]=0;
        
        return dp[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.length()+s2.length()!=s3.length())
                return false;
        
      
        
        int n=s1.length(),m=s2.length();
        
        dp.resize(n,vector<int>(m,-1));
        
        return isinterleave(s1,0,s2,0,"",s3,0);
    }
