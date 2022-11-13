 int n=nums.size();
        
        if(n<4)
            return {};
        
        sort(nums.begin(),nums.end());
        
        set<vector<int>> s;
        
        for(int i=0;i<nums.size()-3;i++)
        {
             
            if(i>0 && nums[i]==nums[i-1])   
                continue;
        
            for(int j=i+1;j<nums.size()-2;j++)
            {
                
                if(j>i+1 && nums[j]==nums[j-1])   
                    continue;
                
                int newt=target-(nums[i]+nums[j]),l=j+1,r=n-1;
                
                while(l<r)
                {
                    long long int g=(long long)nums[l]+(long long)nums[r];
                    
                    if(g==newt)
                    {
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        
                        l++;
                        
                        while(nums[l]==nums[l-1] && l<r)
                            l++;
                        r--;
                        
                         while(nums[r]==nums[r+1] && l<r)
                            r--;
                    }
                    else if(g<newt)
                    {
                        l++;
                    }
                    else
                        r--;
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto i:s)
        {
            vector<int> a=i;
            ans.push_back(a);
        }
        return ans;
