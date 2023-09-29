class Solution {
public:
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
        
    }
    
   };