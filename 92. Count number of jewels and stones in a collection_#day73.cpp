bool mp[52]={false};
      
        int n=jewels.size();
        int count=0;
        for(int i=0;i<stones.size();i++)
        {
            if(find(jewels.begin(),jewels.end(),stones[i])!=jewels.end())
            {
              count++;
            }
        }
      
      return count;
