   map<int,int> mp;
    
    vector<vector<int>> v;
    
    void combo(int i,vector<int> a,int n)
    {
        if(i==n)
        {
            v.push_back(a);
            return;
        }
        
        for(auto it:mp)
        {
            if(it.second==0)
                continue;
            
            a.push_back(it.first);
            
            mp[it.first]--;
            
            combo(i+1,a,n);
            
            a.pop_back();
            
            mp[it.first]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      int n=nums.size();
    mp.clear();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> a;
        combo(0,a,n);
        
        return v;
    }
/*-----------------uses the next_permutation in c++ stl---------------------------------------------------*/

          sort(nums.begin(),nums.end());
        
         vector<vector<int>> ans;
        
        do{
            ans.push_back(nums);
        }
        while(next_permutation(nums.begin(),nums.end()));
        
        return ans;
