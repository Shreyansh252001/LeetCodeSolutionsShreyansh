vector<vector<int>> subsets(vector<int>& nums) 
    {
        int i=0;
        int n=nums.size();
        vector<vector<int>> v;
        
        for(int i=1;i<=pow(2,n);i++)
        {
            vector<int> a;
            
            for(int j=0;j<n;j++)
            {
                if((1<<j) & i)
                    a.push_back(nums[j]);
            }
            
             v.push_back(a);
        }
        
        return v;
    }
