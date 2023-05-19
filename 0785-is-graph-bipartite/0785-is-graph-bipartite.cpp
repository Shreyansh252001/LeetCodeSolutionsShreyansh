class Solution {
public:
    bool ispossible(vector<vector<int>> &graph,int st,char c,vector<char> &color)
    {
        
        color[st]=c;
        
        c=(c=='R')?'B':'R';
        
        for(int it:graph[st])
        {
            if(color[it]==color[st])
            {
                return false;
            }
            else if(color[it]=='@' && !ispossible(graph,it,c,color))
                return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int N=graph.size();
        
        vector<char> color(N,'@');
        
    
        for(int i=0;i<N;i++)
            if(color[i]=='@' && !ispossible(graph,i,'R',color))
                return false;
        
        return true;
    }
};