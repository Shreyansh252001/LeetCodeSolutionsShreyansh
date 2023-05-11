class Solution {
public:
   // https://leetcode.com/problems/uncrossed-lines/discuss/3512331/1035-Uncrossed-Lineorordynamic-programmingororc%2B%2Boror
    
   // vector<vector<int>> dp;
    /*
    int solve(vector<int> nums1,vector<int> nums2,int n,int m)
    {
        if(n<0||m<0)//base case now the index has gone out of bounds
            return 0;
        
        if(dp[n][m]!=-1)// this is the point to be considered , we have saved a lots of recursive cals if we have computed and stored the result in 2-D array
            return dp[n][m];
        
        
        if(nums1[n]==nums2[m])
            return 1+solve(nums1,nums2,n-1,m-1);//adding 1 due to same character found and this time both the pointers have moved one step down
        
        return dp[n][m]=max(solve(nums1,nums2,n-1,m),solve(nums1,nums2,n,m-1));//calling by moving only one pointer as the current index characters are not matching
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
         int n=nums1.size(),m=nums2.size();
        
        dp.resize(n,vector<int>(m,-1));
        
        return dp[n-1][m-1]=solve(nums1,nums2,n-1,m-1);
    }*/
    
   /* //Tabulation
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
         int n=nums1.size(),m=nums2.size();
        
        dp.resize(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        
        return dp[n][m];*/
    
        vector<int> dp;
    
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
        {
            int n=nums1.size();
            int m=nums2.size();
            
            int prev,curr;
            
            bool st=false;
            //first focus on  choosing minimum between n and m and resize the 1-D dp to the smallest one
            
            
            if(n>m)
            {
                st=true;
            }
            
        
            
            if(!st)//n<m
            {
                dp.resize(n+1,0);//initiializing it in such a way that if it would have been 2-D array then the n+1 would have been the column space rather than row space
                
                for(int i=1;i<=m;i++)
                {
                    prev=0;//prev is the 0th row in starting value at 0,0 and for next iteration i-1,j-1
                    
                    for(int j=1;j<=n;j++)
                    {
                        curr=dp[j]; //curr is the value of dp before changing or transforming it in newer array i.e. dp[i-1][j] in 2-d array
                        
                        if(nums2[i-1]==nums1[j-1])
                        {
                            cout<<"first 1"<<"\n";
                            dp[j]=prev+1;//it means if nums1[j-1]==nums2[i-1] the diagonally just up element 
                        }
                        else
                        {
                               cout<<"second 1"<<"\n";
                            dp[j]=max(dp[j-1],curr);//the 1st argument of max is dp[i][j-1] or dp[i-1][j]
                        }
                        
                        prev=curr;//initializing prev with curr because this curr value is now only seen in curr variable and dp[j] is update so to make the diagonal value for next column then prev row's one column backelement wil be this updated prev element
                    }
                }
                
                return dp[n];//returning hte dp[lastrow i.e. m][n]
             }
            
            //else m<n
            dp.resize(m+1,0);
        
                for(int i=1;i<=n;i++)
                {
                    prev=0;
                    
                    for(int j=1;j<=m;j++)
                    {
                        curr=dp[j];
                        
                        if(nums1[i-1]==nums2[j-1])
                        {
                            //cout<<"first 2"<<"\n";
                            dp[j]=prev+1;
                        }
                        else
                        {
                            //cout<<"second 2"<<"\n";
                            dp[j]=max(dp[j-1],curr);
                        }
                        
                        prev=curr;
                    }
                }
                
            return dp[m];
        }
};