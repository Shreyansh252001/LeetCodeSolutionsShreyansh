long int l=0,h=n-1;
        long int mid;
        bool res;
        while(l<=h)
        {
            mid=(l+h)>>1;
            
            res=isBadVersion(mid);
            
            if(res)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
            //res<<flush;
        }
        
        return l;
