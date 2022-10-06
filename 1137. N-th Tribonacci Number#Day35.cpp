  
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        
         int a=0,b=1,c=1;
        int temp;
        
        for(int i=3;i<=n;i++)
        {
            temp=c;
            c+=a+b;
            swap(temp,b);
            swap(temp,a);
        }
        
        return c;
