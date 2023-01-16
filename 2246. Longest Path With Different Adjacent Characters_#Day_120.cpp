class Solution {
public:
    int dfs(int currnode,vector<vector<int>> &c,string &s,int &longestp)
    {
        int longestch=0,secondlongestch=0,longestchfromchild;
        
        for(auto it:c[currnode])
        {
            longestchfromchild=dfs(it,c,s,longestp);
            
            if(s[currnode]==s[it])
            {
                continue;
            }
            
            if(longestch<longestchfromchild)
            {
                secondlongestch=longestch;
                longestch=longestchfromchild;
            }
            else if(secondlongestch<longestchfromchild)
            {
                secondlongestch=longestchfromchild;
            }
        }
        
        longestp=max(longestp,longestch+secondlongestch+1);
        
        return longestch+1;
    }
    
    
    int longestPath(vector<int>& parent, string s)
    {
        int n=parent.size();
        vector<vector<int>> children(n);
        
        for(int i=1;i<n;i++)
        {
            children[parent[i]].push_back(i);
        }
        
        int longestp=1;
        
        dfs(0,children,s,longestp);
        
        return longestp;
    }
};
