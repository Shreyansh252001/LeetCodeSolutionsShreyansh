 -----------------Single Iteration Methods Only -----------------------------------
 Method -1 using single variable
 
 int comp(int a,int b)
    {
        return a==b?0:((a>b)?1:-1);
    }
    bool isMonotonic(vector<int>& a) 
    {
        
        int n=a.size();
        int store=0;
        
        for(int i=0;i<n-1;i++)
        {
            int c=comp(a[i],a[i+1]);
            
            if(c!=0)
            {
                if(store!=0 && c!=store)
                {
                    return false;
                }
                store=c;
            }
        }
        
   return true;
   
   ----------------------------------------------

Method -2 using double variables in substitute of two loops

 bool inc=true,dec=true;
        int n=nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]>nums[i])
                dec=false;
            if(nums[i]>nums[i+1])
                inc=false;
        }
        
        return inc||dec;
