
    int numMatchingSubseq(string s,vector<string> &words)
    {
        vector<pair<int,int>> v[128];
        
        for(int i=0;i<words.size();i++)
        {
            v[words[i][0]].push_back({i,1});
        }
        
        for(char j:s)
        {
            auto b=v[j];
            v[j].clear();
            
            for(auto it:b)
            {
                v[words[it.first][it.second++]].push_back(it);
            }
        }
        
        return v[0].size();
    }
