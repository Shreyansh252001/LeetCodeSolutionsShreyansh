class Solution 
{
public:
    int gcd(int a,int b)
    {
        if(b>a)
            swap(a,b);
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
    
    void rotate(vector<int>& nums, int k) 
    {   
        int n=nums.size(),temp;
        
        k=k%n;
        k=n-k;
        
        for(int i=0;i<gcd(n,k);i++)
        {
            int j=i;
            int d;
            temp=nums[j];
            
            while(1)
            {
                d=j+k;
                
                if(d>=n)
                {
                    d=d-n;
                }
                
                if(d==i)
                    break;
                
                nums[j]=nums[d];
                
                j=d;
            }    
                
            nums[j]=temp;
        }
    }
    
};
