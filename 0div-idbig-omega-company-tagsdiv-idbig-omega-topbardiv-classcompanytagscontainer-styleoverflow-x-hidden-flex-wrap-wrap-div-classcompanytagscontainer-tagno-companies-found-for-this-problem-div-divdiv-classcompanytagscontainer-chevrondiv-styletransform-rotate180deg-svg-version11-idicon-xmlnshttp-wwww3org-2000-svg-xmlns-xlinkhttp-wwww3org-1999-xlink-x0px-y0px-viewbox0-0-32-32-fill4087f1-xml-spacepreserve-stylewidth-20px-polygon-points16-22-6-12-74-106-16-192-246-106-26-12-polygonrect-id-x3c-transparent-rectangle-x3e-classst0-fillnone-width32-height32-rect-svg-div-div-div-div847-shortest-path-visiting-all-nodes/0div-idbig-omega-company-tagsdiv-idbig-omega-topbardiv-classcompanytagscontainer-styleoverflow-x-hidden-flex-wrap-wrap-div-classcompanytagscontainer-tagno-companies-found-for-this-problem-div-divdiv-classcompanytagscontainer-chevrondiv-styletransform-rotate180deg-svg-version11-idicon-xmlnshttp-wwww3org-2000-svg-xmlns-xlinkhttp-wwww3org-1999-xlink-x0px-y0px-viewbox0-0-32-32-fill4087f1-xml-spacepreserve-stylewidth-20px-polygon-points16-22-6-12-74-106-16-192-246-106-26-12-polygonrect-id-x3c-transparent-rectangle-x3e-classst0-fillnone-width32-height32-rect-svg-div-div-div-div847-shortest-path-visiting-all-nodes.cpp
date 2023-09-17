struct obj{
    int origin;
    int distance;
    int mask;
    
    obj(int o,int m,int d)
    {
        origin=o;
        mask=m;
        distance=d;
    }
};

class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
         int n=graph.size();
        
        if(n==1)
            return 0;
        
        queue<obj> q;
        set<pair<int,int>> s;//{origin,mask}
        
       int mask,o,d,all=(1<<n)-1,newmask;
        
        for(int i=0;i<n;i++)
        {
            mask=1<<i;
            q.emplace(obj(i,mask,0));
            s.insert(make_pair(i,mask));
        }
        
        while(!q.empty())
        {
            obj samp=q.front();
            
            q.pop();
            o=samp.origin;
            mask=samp.mask;
            d=samp.distance;
            
            for(int g:graph[o])
            {
                newmask= mask|(1<<g);
                if(newmask==all)
                    return d+1;
                else if(s.count({g,newmask}))
                    continue;
                else
                {
                    q.emplace(obj(g,newmask,d+1));
                    s.insert(make_pair(g,newmask));
                }
            }
        }
        
        return 0;
    }
};