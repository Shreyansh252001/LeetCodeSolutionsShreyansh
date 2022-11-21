   int n=nums.size();
        
          vector<vector<int>> x;
        
    
        sort(nums.begin(),nums.end());
        
        int g;
        
        for(int i=0;i<n;i++)
        {
            int l=i+1,r=n-1;
            
            if(i>0 && nums[i]==nums[i-1])   
                continue;
            
            while(l<r)
            {
                g=nums[i]+nums[l]+nums[r];
                
                if(g==0)
                {  
                    x.push_back({nums[i],nums[l],nums[r]});
                    
                    l++;
                    while(nums[l]==nums[l-1] && l<r)
                        l++;
                    
                    r--;
                    while(nums[r]==nums[r+1] && l<r)
                        r--;
                    
                }
                else if(g<0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        
        return x;
