class Solution {
public:
    vector<vector<int>> dp;
        string f;
        vector<vector<string>> v;
    
    bool ispalin(string s)
    {
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void dfs(string s,int i,int n,vector<string> d)
    {
        if(i==n)
        {
            v.push_back(d);
        }
        
        for(int end=i+1;end<=n;end++)
        {
            f=s.substr(i,end-i);
            
            if(ispalin(f))
            {
                d.push_back(f);
                
                dfs(s,end,n,d);
                
                d.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        dp.resize(n,vector<int>(n,0));
        vector<string> d;
        dfs(s,0,n,d);
        return v;
    
    }
};
