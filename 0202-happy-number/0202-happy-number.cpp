class Solution {
public:
    int value(int n)
    {
        int totalsum=0,d;
        
        while(n>0)
        {
            d=n%10;
            n=n/10;
            
            totalsum+=d*d;
        }
        
        return totalsum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=value(n);
        
        while(fast!=1 && slow!=fast)
        {
            slow=value(slow);
            fast=value(value(fast));
        }
        
        return fast==1;
    }
};