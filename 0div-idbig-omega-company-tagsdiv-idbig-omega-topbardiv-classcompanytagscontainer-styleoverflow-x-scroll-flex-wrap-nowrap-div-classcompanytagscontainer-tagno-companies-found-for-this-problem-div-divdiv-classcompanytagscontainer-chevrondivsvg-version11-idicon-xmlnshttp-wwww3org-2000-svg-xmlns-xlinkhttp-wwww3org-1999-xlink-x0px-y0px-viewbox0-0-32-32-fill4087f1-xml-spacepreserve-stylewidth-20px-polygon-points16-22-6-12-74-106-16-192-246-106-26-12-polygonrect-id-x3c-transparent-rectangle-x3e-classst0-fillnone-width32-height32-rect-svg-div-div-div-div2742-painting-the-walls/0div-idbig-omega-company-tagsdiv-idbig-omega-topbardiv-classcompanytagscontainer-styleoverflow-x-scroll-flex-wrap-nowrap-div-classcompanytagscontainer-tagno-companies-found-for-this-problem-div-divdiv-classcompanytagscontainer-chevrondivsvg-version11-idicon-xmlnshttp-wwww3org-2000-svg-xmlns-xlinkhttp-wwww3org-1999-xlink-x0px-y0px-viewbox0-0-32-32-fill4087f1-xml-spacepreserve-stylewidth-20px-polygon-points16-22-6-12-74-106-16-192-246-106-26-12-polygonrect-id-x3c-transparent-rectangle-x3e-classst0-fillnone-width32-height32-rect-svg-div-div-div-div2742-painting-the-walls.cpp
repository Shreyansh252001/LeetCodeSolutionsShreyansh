class Solution {

public:
    vector<vector<int>> memo;
    int n;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n, vector(n + 1, -1));
        return dp(0, n, cost, time);
    }
    
   // int paintWalls(vector<int>& cost, vector<int>& time) {
//         With cost cost[i],
// we buy time[i],
// and we can additionally finish time[i] walls,
// so actually can finish time[i] + 1 walls.

//So cost[i] to finish time[i] + 1 walls,
//we need the minimum total cost to finish n walls.

// dp[t] = c means the minimum cost to finish t walls is c.

// Initially dp[0] = 0 and dp[i > 0] = inf

// Iterate each cost[i], time[i],
// update dp[j] with this dp equation
// dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i])

// Finally return result dp[n]

        
        

    int dp(int i, int remain, vector<int>& cost, vector<int>& time) { 
        if (remain <= 0) {
            return 0;
        }
        
        if (i == n) {
            return 1e9;
        }
        
        if (memo[i][remain] != -1) {
            return memo[i][remain];
        }
        
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], cost, time);
        int dontPaint = dp(i + 1, remain, cost, time);
        memo[i][remain] = min(paint, dontPaint);
        return memo[i][remain];
    }
};
