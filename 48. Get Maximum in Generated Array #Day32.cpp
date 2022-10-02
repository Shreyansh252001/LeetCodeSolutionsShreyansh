int getMaximumGenerated(int n) 
    {
        if(n==0||n==1)
            return n;
        vector<int> v(n+1);
        v[0]=0;
        v[1]=1;
        int q,maxi=0;
        for(int i=2;i<=n;i++)
        {
            q=i/2;
            
            if(i&1)
                v[i]=v[q]+v[q+1];
            else
                v[i]=v[q];
            
            maxi=max(v[i],maxi);
        }
        
        return maxi;
        
        /* another optimised approach
          if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        vector<int>nums(n+1,0);
        nums[0] = 0;
        nums[1] = 1;
        int i = 1;
        while((2*i+1)<=n)
        {
            nums[2*i] = nums[i];
            nums[2*i+1] = nums[i] + nums[i+1];
            i++;
        }
        int maxArray = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxArray = max(maxArray,nums[i]);
        }
        return maxArray;
    }*/
    }
