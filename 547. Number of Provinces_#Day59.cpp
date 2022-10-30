  class Union1
  {
    vector<int> parent;
    vector<int> rank;
    
    public:
    
    Union1(int n)
    {
      parent.resize(n);
      
      for(int i=0;i<n;i++)
      {
        parent[i]=i;
      }
      
      rank.resize(n,0);
    }
    
    
    int findp(int a)
    {
      return parent[a]==a?a:findp(parent[a]);
    }
    
    void un(int a,int b)
    {
      int pa=findp(a);
      
      int pb=findp(b);
      
      if(pa!=pb)
      {
        if(rank[pa]<=rank[pb])
        {
          rank[pb]++;
          parent[pa]=pb;
        }
        else
        {
          rank[pa]++;
          parent[pb]=pa;
        }
      }
      
    }
    
    int count(int n)
    {
      int count=0;
      
      for(int i=0;i<n;i++)
      {
        if(parent[i]==i)
          count++;
      }
      
      return count;
    }
    
  };
  
    int findCircleNum(vector<vector<int>>& isC) 
    {
        int n=isC.size();
      
      Union1 *obj=new Union1(n);
      
      for(int i=0;i<n-1;i++)
      {
        for(int j=i+1;j<n;j++)
        {
          if(isC[i][j])
          {
            obj->un(i,j);
          }
        }
      }
      
     
      
      return obj->count(n);
    }
