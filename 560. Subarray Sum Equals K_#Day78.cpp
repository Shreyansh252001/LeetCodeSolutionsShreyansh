  int j=0;
        int n=nums.size(),count=0,sum=0;
      
        map<int,int> mp;
        mp[0]={1};
      
        while(j<n)
        {
          sum+=nums[j];
        
          
          if(mp.find(sum-k)!=mp.end())
          {
            count+=mp[sum-k];
          }
        
            mp[sum]++;
          
          j++;
        }
      
      return count;
