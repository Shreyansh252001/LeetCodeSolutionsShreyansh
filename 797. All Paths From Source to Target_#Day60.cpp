 vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) 
    {
        vector<vector<int>> res;
      
      vector<int> ans;
      
      queue<string> q;
      
      string s="";
      
      q.push("0");
      
      string g;
      char f;
      
        int m,n=adj.size();
      
      while(!q.empty())
      {
        int m=q.size();
        
        while(m--)
        {
          g=q.front();
          
          q.pop();
            
          f=g.back();
          
          if(f==('0'+n-1))
          {
            
            for(int i=0;i<g.length();i++)
            {
                ans.push_back(g[i]-'0');
            }
            res.push_back(ans);
            ans.clear();
            continue;
          }
          
          for(int it:adj[f-'0'])
          {
            char c='0'+it;
            q.push(g+c);  
          }
        }
      }
      
      return res;
    }
