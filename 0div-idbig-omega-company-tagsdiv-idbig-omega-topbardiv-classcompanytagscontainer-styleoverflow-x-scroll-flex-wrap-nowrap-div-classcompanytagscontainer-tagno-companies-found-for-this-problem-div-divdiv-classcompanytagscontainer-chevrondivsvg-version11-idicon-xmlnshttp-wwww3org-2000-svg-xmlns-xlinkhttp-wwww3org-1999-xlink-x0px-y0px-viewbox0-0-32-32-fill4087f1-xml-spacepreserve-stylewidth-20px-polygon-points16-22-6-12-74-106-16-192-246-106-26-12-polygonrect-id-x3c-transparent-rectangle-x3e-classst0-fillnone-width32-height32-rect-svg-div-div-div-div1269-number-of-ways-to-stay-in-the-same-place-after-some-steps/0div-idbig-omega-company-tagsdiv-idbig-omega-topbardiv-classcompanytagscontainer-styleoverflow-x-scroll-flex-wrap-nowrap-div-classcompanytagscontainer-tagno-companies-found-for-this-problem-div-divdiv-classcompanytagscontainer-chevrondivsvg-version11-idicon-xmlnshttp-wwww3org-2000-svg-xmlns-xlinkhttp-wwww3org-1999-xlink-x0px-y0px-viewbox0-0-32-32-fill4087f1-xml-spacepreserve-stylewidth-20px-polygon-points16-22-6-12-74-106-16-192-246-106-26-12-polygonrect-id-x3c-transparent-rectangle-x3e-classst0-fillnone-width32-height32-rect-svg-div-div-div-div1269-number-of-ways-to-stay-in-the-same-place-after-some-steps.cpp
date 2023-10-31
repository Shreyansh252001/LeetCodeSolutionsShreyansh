class Solution {

public:
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    int arrLen;
    
    /*int dp(int curr, int remain) 
    {
        if (remain == 0) 
        {
            if (curr == 0) 
            {
                return 1;
            }
            
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1);
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }*
    
    int dp(int start,int steps)
    {
        if(start<0 || start>=n)
            return 0;
        
        if(steps==0)
        {
            return start==0?1:0;
        }
        
        if(memo[start][steps]!=-1)
            return memo[start][steps];
        
        return memo[start][steps]=(dp(start-1,steps-1)%MOD+dp(start+1,steps-1)%MOD+dp(start,steps-1)%MOD);
        
    }
    
    int numWays(int steps, int arrLen) {
       * arrLen = min(arrLen, steps);
        this->arrLen = arrLen;
        memo = vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps);*
        
        arrLen=min(arrLen,steps);
        
        n=arrLen;
        
        memo.resize(arrLen,vector<int>(2*steps+1,0));
        
        //(start,steps)
        return dp(0,steps);
    }*/

    
 
    
    int dp(int curr, int remain) {
        if (remain == 0) {
            if (curr == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1);
        
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        this->arrLen = arrLen;
        memo = vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps);
    }

};