
    {
        long int a=LONG_MIN,b=LONG_MIN,c=LONG_MIN,n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(a==nums[i] || b==nums[i] || c==nums[i])
                continue;
            
            if(a<nums[i])
            {
                c=b;
                b=a;
                a=nums[i];
            }
            else if(b<nums[i])
            {
                c=b;
                b=nums[i];
            }
            else if(c<nums[i])
            {
                c=nums[i];
            }
        }
        
        return c==LONG_MIN?(int)a:(int)c;
