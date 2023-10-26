class Solution {
public:
    const int MOD=1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        set<int> s(arr.begin(),arr.end());
        
        unordered_map<long long int,long long int> dp;
        
        for(auto it:arr)
            dp[it]=1;
        
          for (int i : arr) {
            for (int j : arr) {
                if (j > std::sqrt(i)) break;
                if (i % j == 0 && s.find(i / j) != s.end()) {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }
        /*for(int it:arr)
        {
            for(int it1:arr)
            {
                if(it1>sqrt(it))
                {
                    break;
                }
                
                if(it%it1==0 && s.find(it/it1)!=s.end())
                {
                    long long temp=dp[it1]*dp[it/it1];
                    
                    if(it1==(it/it1))
                    {
                        dp[it]=(dp[it]+temp)%MOD;
                    }
                    else
                    {
                        dp[it]=(dp[it]+temp*2)%MOD;
                    }
                }
            }
        }*/
        
         int result = 0;
        for (auto& [_, val] : dp) {
            result = (result + val) % MOD;
        }
        return result;
        
        /*
        int result=0;
        
        for(auto it:dp)
        {
            result+=it.second;
            result=result%MOD;
        }
        
        return result;*/
    }
};