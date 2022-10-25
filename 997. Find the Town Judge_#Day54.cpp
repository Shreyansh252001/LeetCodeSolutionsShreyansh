int m=trust.size();
        
        if(m==0)
            return n==1?1:-1;
        
        if(m==1)
            return trust[0][1];
        
        vector<int> ans(n+1,0);
        
        for(int i=0;i<m;i++)
        {  ans[trust[i][1]]++;ans[trust[i][0]]--;}
        
        int maxi=-1,index=-1;
        
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==n-1)
            {  
                if(maxi==-1)
                { maxi=n-1;index=i;}
                else
                index=-1;
            }
        }   
        return index;
