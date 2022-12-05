bool cmp=[](pair<int,string> &a,pair<int,string> &b)
   {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k)
    {
          int n=words.size();
        
     priority_queue<pair<int,string>,vector<pair<int,string>>> pq;
        
        
         // priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,(pair<int,int> &a,pair<int,int> &b){return a.second>=b.second;}> q;
        
        sort(words.begin(),words.end());
        
        int count=1,i=0;
        
        for(;i<n-1;i++)
        {
            if(words[i]==words[i+1])
            {
                count++;
            }
            else
            {
                pq.push({count,words[i]});
                count=1;
            }
        }
        
        if(n!=1 && words[i]==words[i-1])
        {
            count++;
        }
    
        pq.push({count,words[i]});
        
        vector<string> ans;
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
