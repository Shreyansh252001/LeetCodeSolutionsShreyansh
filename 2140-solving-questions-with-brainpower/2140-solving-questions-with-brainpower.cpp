class Solution {
public:
  /*  
  Recursion
  
  int takenottake(vector<vector<int>> &questions,int i,int n)
    {
        if(i>=n)//out of range return zero
            return 0;
        
        return max(questions[i][0]+takenottake(questions,i+questions[i][1]+1,n),takenottake(questions,i+1,n));
        //if talking the current index add the points for it and go beyond the range i.e i+questions[i][1]+1 to the just next index after range
                                //OR
        //if not talking the current index just go to next index as you are free to go to the next index
    }
    
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
        
       return takenottake(questions,0,n); 
    }
    */
    /*Memoization( 1-D dp)

    
    vector<long long int> dp;
    
    long long int n;
    
    long long int takenottake(vector<vector<int>> &questions,long long int i,long long int n)
    {
         if(i>=n)
            return 0;
         
        if(dp[i]!=-1)
            return dp[i];
         
        return dp[i]=max(questions[i][0]+takenottake(questions,i+questions[i][1]+1,n),takenottake(questions,i+1,n));
    }
    
    long long mostPoints(vector<vector<int>>& questions)
    {
       n=questions.size();
       
       dp.resize(n,-1);
       
       return takenottake(questions,0,n); 
    }
    
    */
    
    /*Tabulation (bottom up APPROACH) */
     long long mostPoints(vector<vector<int>>& questions)
    {
       long int n=questions.size();
       
       vector<long long int> dp(n+1,0);
         
        dp[n]=questions[n-1][0];
         
       for(int i=n-1;i>=0;i--)
       {
           if(i+questions[i][1]+1<n)
               dp[i]=questions[i][0]+dp[i+questions[i][1]+1];
           else
               dp[i]=questions[i][0];
           
           dp[i]=max(dp[i],dp[i+1]);
       }
         
       return dp[0];
    }
   // */
};