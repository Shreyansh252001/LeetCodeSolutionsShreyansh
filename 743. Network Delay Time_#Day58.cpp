
    vector<vector<pair<int,int>>> adj;
  
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        queue<int> pq;
      
        adj.resize(n+1);
      
      for(auto it:times)
      {
        adj[it[0]].push_back(make_pair(it[1],it[2]));
      }
      
     // cout<<"=--------"<<"\n";

      pq.push(k);
      
      vector<int> temp(n+1,INT_MAX);
      temp[k]=0;
      
      int node,val,maxi=INT_MIN;
    
      while(!pq.empty())
      {
        
        node=pq.front();
        pq.pop();
        
        for(auto it:adj[node])
        {
          int arrtime=it.second+temp[node];
          
          if(arrtime<temp[it.first])
          {
            temp[it.first]=arrtime;
            pq.push(it.first);
          }
        }
        
      }
      
      for(int i=1;i<=n;i++)
        maxi=max(maxi,temp[i]);
      
      return maxi==INT_MAX?-1:maxi;
      }
