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
        if((2*pairspickedcount)>=nums.size())//if 2*pairs==n means the all elements are there in soem or the oter way return 0 no further possibility
            return 0;
        
        if(dp[mask]!=-1)// if current mask already calculated the maximum then return it
            return dp[mask];
        
        int maxscore=0;
        
        //doulbe loop to pick different elements in various combinations using this we are not compulsiated to pick one index of i and fix it with any other index j one time we can select variably ith and jth elements
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(mask&(1<<i) || mask&(1<<j))//if any of the element i or j is picked then one of the mask or both the mask depending on which index is picked will return 1 
                {
                    continue;
                }
                
                int newmask=mask|(1<<i)|(1<<j);//if picking the pair then register them picked in the mask by setting the index i's and j's bit representation's 1 positions in mask as 1
                
                int pickingscore=gcd(nums[i],nums[j])*(pairspickedcount+1);//caclulating the cost as per formula given in  the question
                
                int score=backsize(nums,newmask,pairspickedcount+1);//moving ahead after pciking two indexes i and j
                
                maxscore=max(maxscore,score+pickingscore);//registering the current returned score + picking score of current i and j oth collectively as maxscore if the total is maxscore
                
            }
        }
        
       return dp[mask]=maxscore;//for the given mask or the start of ith and jth picking return and store the maxscore calculated so far
    }
    
    int maxScore(vector<int>& nums)
    {
       n=nums.size();
        
       dp.resize(1<<n,-1);//creating a dp array with maximum size possible i mean to say if the number of elements is 3 then the way we decide to pick or not pick an element in subsequence using the formula 2^3 same way we are reserving a space here 2^n 
        
       return backsize(nums,0,0);//second parameter denotes the current mask to be used for detecting wheter the given index is picked up or not
                                // third parameter is the number of pairs picked up 
    }
    
    
};