class TweetCounts {
public:
    map<string,vector<long int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if(mp.find(tweetName)!=mp.end())
        {
          mp[tweetName].push_back(time);
        }
        else
        {
          mp[tweetName]={time};
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int s, int e) {
        int interval=60;
      
        if(freq=="hour")
        {
          interval=3600;
        }
        else if(freq=="day")
        {
          interval=86400;
        }
      
        vector<int> ans;
      
        for(int i=0;i<=(e-s)/interval;i++)
        {
          ans.push_back(0);
        }
      
        vector<long int> timel=mp[tweetName];
        int idx;
        
        for(auto it:timel)
        {
          if(it>=s && it<=e)
          {
            idx=(it-s)/interval;
            
            ans[idx]++;
          }
        }
      
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
