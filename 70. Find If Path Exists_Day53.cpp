vector<int> parent;
    vector<int> rank;
    
//     struct union1
//     {
//         int pu,pv; 
//         union1(n)
//         {
//             parent.resize(n);
        
//             for(int i=0;i<n;i++)
//                 parent[i]=i;
            
//             rank.resize(n,0);
//         }
//     };
    
    int findp(int a)
    {
        return parent[a]==a?a:findp(parent[a]);
    }
    
    void findun(int a,int b)
    {   
        int pu=findp(a);
        int pv=findp(b);
        
        if(pu==pv)
            return;
        
        if(rank[pu]>=rank[pv])
        {
            parent[pv]=pu;
            rank[pu]++;
        }
        else
        {
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        //union1* obj=new union1(n);
         parent.resize(n);
        
            for(int i=0;i<n;i++)
                parent[i]=i;
            
             rank.resize(n,0);
        
        for(auto it:edges)
        {
            findun(it[0],it[1]);
        }
        
        return findp(source)==findp(destination);
    }
