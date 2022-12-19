class Solution {
public:
  class Union1{
    
      int par,child;
    
     vector<int> p;
public:
    Union1(int n)
    {
      p.resize(n);
      
      for(int i=0;i<n;i++)
          p[i]=i;
    }
    
    int findp(int x)
    {
      return (x==p[x])?x:findp(p[x]);
    }
    
    void union1(int x,int y)
    {
      int par=findp(x);
      int child=findp(y);
      
      if(par!=child)
      {
        p[child]=par;
      }
    }
    
  };
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest)
    {
      
      Union1 obj(n);
      
        for(int i=0;i<edges.size();i++)
        {
          obj.union1(edges[i][0],edges[i][1]);    
        }
      
      return obj.findp(source)==obj.findp(dest);
    }
};
