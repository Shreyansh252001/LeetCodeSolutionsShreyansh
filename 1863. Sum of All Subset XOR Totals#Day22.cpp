int n=nums.size(),sum,total=0;
        
        for(int i=0;i<pow(2,n);i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i)
                {
                   sum^=nums[j]; 
                }
            }
            total+=sum;
        }
        
        return total;
