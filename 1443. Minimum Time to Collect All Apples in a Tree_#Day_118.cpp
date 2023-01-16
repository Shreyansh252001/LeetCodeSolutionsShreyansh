class Solution {
public:
    vector<bool> vis;
    
    int dfs(int i,int p,vector<vector<int>> &a,vector<bool> &st)
    {
        int g,totaltime=0;
        
        for(int it:a[i])
        {
            if(it!=p)
            {
                g=dfs(it,i,a,st);
                
                if(g!=0||st[it])
                    totaltime+=g+2;
            }
        }
        
        return totaltime;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> a(n);
        
        vis.resize(n,false);
        
        for(auto it:edges)
        {
           a[it[0]].push_back(it[1]);
            a[it[1]].push_back(it[0]);
        }
        
        return dfs(0,-1,a,hasApple);
    }
};
