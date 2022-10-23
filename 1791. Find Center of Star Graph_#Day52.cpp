int n=edges.size();
        vector<int> deg(n+2,0);
        
        for(int i=0;i<n;i++)
        {
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        
        int i=0;
        
        while(i<=n+1)
            if(deg[i]==n)
                break;
            else
                i++;
        
        return i;
