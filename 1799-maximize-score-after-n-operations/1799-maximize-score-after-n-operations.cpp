class Solution {
public:
    vector<int> dp;
    int n;
    
    long int gcd(long int a,long int b)
    {
       if(a<b)
           swap(a,b);
        
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
    
    int backsize(vector<int> &nums,int mask,int pairspickedcount)
    {
        if((2*pairspickedcount)>=nums.size())
            return 0;
        
        if(dp[mask]!=-1)
            return dp[mask];
        
        int maxscore=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(mask&(1<<i) || mask&(1<<j))
                {
                    continue;
                }
                
                int newmask=mask|(1<<i)|(1<<j);
                
                int pickingscore=gcd(nums[i],nums[j])*(pairspickedcount+1);
                
                int score=backsize(nums,newmask,pairspickedcount+1);
                
                maxscore=max(maxscore,score+pickingscore);
                
            }
        }
        
       return dp[mask]=maxscore;
    }
    
    int maxScore(vector<int>& nums)
    {
       n=nums.size();
        
       dp.resize(1<<n,-1);
        
       return backsize(nums,0,0);
        
    }
    
    
};