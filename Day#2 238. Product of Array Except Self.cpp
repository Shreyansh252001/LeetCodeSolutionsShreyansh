
        long int ans=1;
        int n=nums.size(),count=0,index;
        
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]!=0)
                ans=ans*nums[i];
            else
            {index=i;count++;}
        }
        if(count!=0)
        {
                fill(nums.begin(),nums.end(),0);
            if(count<=1)
            {
                nums[index]=ans;
            }
        }
        else
            for(int i=0;i<n;i++)
            {
                    nums[i]=ans/nums[i];
            }

        return nums;
