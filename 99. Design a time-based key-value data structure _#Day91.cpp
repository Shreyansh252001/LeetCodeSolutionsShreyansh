
   map<string,vector<pair<int,string>>> mp; 
    TimeMap() {
      
    }
    
    void set(string key, string value, int timestamp) {
          mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) 
    {
        if(mp.find(key)==mp.end())
        {
          return "";
        }
      
        int l=0,r=mp[key].size(),n=r,mid;
      
        while(l<r)
        {
          mid=(l+r)>>1;
          
          if(mp[key][mid].first<=timestamp)
          {
            l=mid+1;
          }
          else
          {
            r=mid;
          }
        }
    
     /* if(l < n && mp[key][l].first < timestamp) {
       l++;
      }*/
       
      if(r==0)
          return "";
      
      return mp[key][r-1].second;
