
/*Using Union Find*/
class Solution 
{
public:
    class union1
    {
        public:
        
        int parx,pary;
        
        vector<int> par;
        vector<int> rank;
        
        union1(int n)
        {
            par.resize(n+1);
            
            for(int i=1;i<=n;i++)
                par[i]=i;
            
            rank.resize(n+1,0);
        }
        
        int findp(int i)
        {
            return (par[i]==i)?i:findp(par[i]);
        }
        
        void union_find(int x,int y)
        {
            parx=findp(x);
            pary=findp(y);
            
            if(parx!=pary)
            {
                if(rank[parx]>rank[pary])
                {
                    par[pary]=parx;
                }
                else if(rank[parx]<rank[pary])
                {
                    par[parx]=pary;
                }
                else
                {
                    par[pary]=parx;
                    rank[parx]++;
                }
            }
        }
    };
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        union1 *obj=new union1(n);
        
        for(int i=1;i<=n;i++)
        {
            for(int neigh: adj[i])
            {
                if(obj->findp(neigh)==obj->findp(i))
                    return false;
                
                    obj->union_find(adj[i][0],neigh);
            }
        }
        
        return true;
    }
};
