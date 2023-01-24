vector<bool> ans(n+1,false);
        
        int cnt=-1;
        
        for(int i=0;i<trust.size();i++)
        {
            ans[trust[i][0]]=true;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!ans[i])
            {
                if(cnt != -1)
                    return -1;
                cnt = i;
            }
        }
        
        if(cnt==-1)
            return -1;
        
        int g=cnt;
        cnt=0;
        
        for(int i=0;i<trust.size();i++)
        {
            if(trust[i][1]==g)
            {
                cnt++;
            }
        }
        
        return cnt==n-1?g:-1;
