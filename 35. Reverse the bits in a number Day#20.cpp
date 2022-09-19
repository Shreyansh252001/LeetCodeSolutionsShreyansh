 uint32_t reverseBits(uint32_t n) {
        if(n==0)
                return 0;
        
        uint32_t sum=0;
        int a;
        
        for(int i=0;i<32;i++)
        {
            sum<<=1;
            if(n&1)
                sum+=1;
            n>>=1;
        }
        
        return sum;
    }
