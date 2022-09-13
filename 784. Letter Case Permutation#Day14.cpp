        if(i==s.length())
        {   a.push_back(s);return;}
        
        
       dfs(s,a,i+1);
        
        if(isalpha(s[i]))
        {
        s[i]=s[i]^(1<<5);
        
       dfs(s,a,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> a;
        
        dfs(s,a,0);
        
        return a;
    }
