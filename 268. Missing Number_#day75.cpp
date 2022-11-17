 int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {  sum^=nums[i];
        sum^=i;}
        
        sum^=n;
        
        return sum;
