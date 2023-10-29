class Solution {
public:
        map<char,int> mp;
    vector<vector<long long int>> dp;
    const int mod=1000000007;
    
    int count(char c,int n)
    {
        if(n==0)
            return 1;
        
        int ct=0;
        
      //  for(auto it:mp[c])
      //      ct+=count(it,n-1);
        
        return ct;
    }
    
    int countVowelPermutation(int n) 
    {
        //https://leetcode.com/problems/count-vowels-permutation/discuss/4216117/98.55-DP-Transition-Matrix
       /*'a'*/ mp[0]=1;//{'e'};
        /*'e'*/mp[1]=2;//{'a','i'};
       /*'i'*/ mp[2]=4;//{'a','e','o','u'};
       /*'o'*/ mp[3]=2;//{'i','u'};
       /*'u'*/ mp[4]=1;//{'a'};
        
        
        char c='a';
        
        dp.resize(2,vector<long long int>(5,0));
        
        for(int i=0;i<5;i++)
            dp[0][i]=1;
        
        for (int j = 1; j<n; j++) 
        {
            dp[j&1][0] = (dp[(j-1)&1][1]) % mod;
            
            dp[j&1][1] = (dp[(j-1)&1][0] + dp[(j-1)&1][2]) % mod;
            
            dp[j&1][2] = (dp[(j-1)&1][0] + dp[(j-1)&1][1] + dp[(j-1)&1][3] + dp[(j-1)&1][4]) % mod;
            
            dp[j&1][3] = (dp[(j-1)&1][2] + dp[(j-1)&1][4]) % mod;
            
            dp[j&1][4] = (dp[(j-1)&1][0]) % mod;
        }
        
      /*  for(int i=1;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
            
                for(auto it:mp)
                dp[i][j]+=dp[i-1][mp[it]-'a'];
                
            }
        }*/
        
        long long int sum=0;
        
        for(int j=0;j<5;j++)
            sum=(sum+dp[(n-1)&1][j])%mod;
        
        return sum;
    }
};