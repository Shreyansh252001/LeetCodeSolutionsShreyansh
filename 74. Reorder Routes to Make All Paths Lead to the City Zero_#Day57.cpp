vector<vector<int>> adj;
    vector<bool> vis;
    
    int dfs(int st)
    {
      //  if(vis[abs(st)])
          //  return 0;
        
        int count=0;
            
        vis[abs(st)]=true;
        
        for(int it:adj[abs(st)])
        {
            if(!vis[abs(it)])
            {
                if(it>=0)
                    count++;
                    count+=dfs(it);
            }
        }
        
        return count;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        vis.resize(n,false);
        for(int i=0;i<n-1;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-(connections[i][0]));
        }
        return dfs(0);
    }
