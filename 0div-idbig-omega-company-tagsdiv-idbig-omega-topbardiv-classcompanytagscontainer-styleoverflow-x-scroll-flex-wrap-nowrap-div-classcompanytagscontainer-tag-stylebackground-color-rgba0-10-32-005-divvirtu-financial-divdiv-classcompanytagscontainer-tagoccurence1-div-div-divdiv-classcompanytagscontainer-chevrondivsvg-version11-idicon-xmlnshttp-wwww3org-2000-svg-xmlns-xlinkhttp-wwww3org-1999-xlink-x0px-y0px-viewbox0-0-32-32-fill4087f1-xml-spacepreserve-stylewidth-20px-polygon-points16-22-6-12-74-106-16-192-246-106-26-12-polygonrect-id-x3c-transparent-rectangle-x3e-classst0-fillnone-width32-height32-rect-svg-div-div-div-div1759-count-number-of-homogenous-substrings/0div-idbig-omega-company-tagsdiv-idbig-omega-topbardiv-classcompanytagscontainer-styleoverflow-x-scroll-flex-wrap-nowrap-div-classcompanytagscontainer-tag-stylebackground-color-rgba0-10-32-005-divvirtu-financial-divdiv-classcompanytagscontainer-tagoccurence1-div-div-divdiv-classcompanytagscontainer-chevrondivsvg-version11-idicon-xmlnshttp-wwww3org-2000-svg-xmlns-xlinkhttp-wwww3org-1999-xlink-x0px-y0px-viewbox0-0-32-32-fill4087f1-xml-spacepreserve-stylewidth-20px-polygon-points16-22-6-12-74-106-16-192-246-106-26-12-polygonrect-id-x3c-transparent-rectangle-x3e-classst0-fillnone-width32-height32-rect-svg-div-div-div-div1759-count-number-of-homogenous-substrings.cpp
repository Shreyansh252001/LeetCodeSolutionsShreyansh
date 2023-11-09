class Solution {
public:
    const int MOD=1000000007;
    
    int countHomogenous(string s) 
    {
        long int sum=0;
        
        long long int i=0,count=1,n=s.length();
        
        if(n==1)
            return 1;
        
        while(i<n-1)
        {
            count=1;
            
            while(i<n-1 && s[i]==s[i+1])
            {
                i++;
                count++;
            }
            
            if(i<n-1)
                sum+=((count)*(count+1)/2);
            
             i++;
        }
        
        if(s[n-2]!=s[n-1])
            sum++;
        else
        {
            sum+=(count*(count+1))/2;
            sum=sum%MOD;
        }
        
        return sum;
    }
};