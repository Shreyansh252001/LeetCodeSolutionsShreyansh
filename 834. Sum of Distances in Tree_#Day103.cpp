class Solution 
{
public:
    void dfs_count_subtree(vector<vector<int>> &graph,int i,int parent,vector<int> &count_subtree,vector<int> &res)
    {
        for(auto x:graph[i])
        {
            if(x==parent)
            {
                continue;
            }
            dfs_count_subtree(graph,x,i,count_subtree,res);
            count_subtree[i]+=count_subtree[x];
            res[i]+=res[x]+count_subtree[x];

        }
        count_subtree[i]+=1;
    }
    void dfs(vector<vector<int>> &graph, int sv , vector<int> &res , int parent , vector<int> &count_subtree , int n)
    {
        for(auto x:graph[sv])
        {
            if(x==parent)
            {
                continue;
            }
            res[x]=res[sv]+(n-2*count_subtree[x]);
            dfs(graph,x,res,sv,count_subtree,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for(int i=0;i<n-1;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> subtree(n,0);
        vector<int> res(n,0);
        dfs_count_subtree(graph,0,-1,subtree,res);
        dfs(graph,0,res,-1,subtree,n);
        return res;
    }
};
