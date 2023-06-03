class Solution {
public:
    vector<int> time;
    vector<vector<int>> adj;
    int max_time=INT_MIN;
    
    int ans(int hid,vector<int> &inftime,int time)
    {
        int res=0;
        
        for(int it:adj[hid])
        {
            res=max(res,time+inftime[hid]);
            res=max(res,ans(it,inftime,time+inftime[hid]));
        }
    
        return res;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        time.resize(n,0);
        adj.resize(n);
        
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        
        return ans(headID,informTime,0);
    }
};