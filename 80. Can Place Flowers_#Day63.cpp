 int n=f.size(),count=0,count1=0;
    
      
      for(int i=0;i<n && m>0;i++)
      {
        count=0;
        
        if(f[i]==0)
        {
          if(i==0 || f[i-1]==0)
          {
            count++;
          }
          
          if(i==n-1 || f[i+1]==0)
          {
            count++;
          }
          
          if(count==2)
          { f[i]=1; count1++;}
        }
      }
      
     return count1>=m;
