class Solution {
public:
   /*
   Recursion
   
     int l,h;
    
    int ans(string s,int zero,int one)
    {
        int count=0,n=s.length();
        
        if(n>=l && n<=h)
        {    count++; 
            if(n==h)
                return count;
        }//if current string length is >=l && <=h then make it a part of answer do count++ as this particular string will never be seen again in recursive calls it will be modified
        
        string d=s;
       
        for(int i=0;i<zero;i++)
            d+='0';
        
        n=d.length();
        
        if(n<=h)
            count+=ans(d,zero,one);//if the new string length is less than or eual to hgih then only call for next.Done this to save extra calls
        
         d=s;
    
        for(int i=0;i<one;i++)
            d+='1';
        
        n=d.length();
        
        if(n<=h)
            count+=ans(d,zero,one);//if the new string length is less than or eual to hgih then only call for next.Done this to save extra calls
        
        return count;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        l=low;
        h=high;
        
        return ans("",zero,one);
    }*/
    
    /*Memoization*/
    int l,h,z1,o1;
    
    const int mod=1e9+7;
    
    vector<int> dp;
    
    int dfs(int end)
    {
        if(dp[end]!=-1)
                return dp[end];
        
        int count=0;
        
        if(end>=z1)
            count+=dfs(end-z1);
        
        if(end>=o1)
             count+=dfs(end-o1);
        
        return dp[end]=count%mod;
    }
    
     int countGoodStrings(int low, int high, int zero, int one) 
    {
        l=low;
        h=high;
        z1=zero;
        o1=one;
         
         int count=0;
         
         dp.resize(high+1,-1);
         
         dp[0]=1;
        
         for(int end=low;end<=high;end++)
         {     
             count+=dfs(end);
                count%=mod;
         }
         
         return count;
    }
};