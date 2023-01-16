//Union-find
class Solution {
public:
    vector<int> parent;
    
    int findp(int i)
    {
        return parent[i]==i?i:findp(parent[i]);    
    }
    
    void performunion(int i,int j)
    {
        int x=findp(i);
        int y=findp(j);
        
        if(x<y)
        {
            parent[y]=x;
        }
        else if(x>y)
        {
            parent[x]=y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        int n=s1.length();
        
        parent.resize(26);
        
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        
        for(int j=0;j<n;j++)
        {
            performunion(s1[j]-'a',s2[j]-'a');
        }
        
        string ans="";
        
        for(int i=0;i<baseStr.length();i++)
        {
            ans+=findp(baseStr[i]-'a')+'a';
        }
        
        return ans;
    }
};




//dfs
class Solution {
public:
    vector<bool> vis;
    
    void dfs(int i,vector<vector<int>> &adj,vector<int> &comp,int &minchar)
    {
        vis[i]=1;
        
        comp.push_back(i);
        
        minchar=min(minchar,i);
        
        for(int j=0;j<26;j++)
        {
            if(!vis[j] && adj[i][j])
            {
                dfs(j,adj,comp,minchar);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        int n=s1.length();
        
        vis.resize(26,false);
        
        vector<vector<int>> adj(26,vector<int>(26,0));
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            adj[s1[i]-'a'][s2[i]-'a']=1;
            adj[s2[i]-'a'][s1[i]-'a']=1;
        }
        
        for(int i=0;i<26;i++)
        {
            if(!vis[i])
            {
                vector<int> component;
                
                int minchar=27;
                
                dfs(i,adj,component,minchar);
                
                for(int c:component)
                {
                    mp[c]=minchar;
                }
            }
        }
        
        string res="";
        
        for(char c:baseStr)
        {
            res+=mp[c-'a']+'a';
        }
        
        return res;
    }
};
