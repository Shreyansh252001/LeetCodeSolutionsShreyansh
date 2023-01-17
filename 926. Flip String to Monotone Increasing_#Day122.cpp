class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length(),num=0,ans=0;// ans will track '0''s to be made '1''s
        // num will track '1''s to be made '0''s
        
       // vector<int> dp(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
              ++num; // dp[i]=dp[i-1]+1;//adding one at end to string means continuing the tradition of 0000...0011111
            else
            {
                ans=min(ans+1,num);//ans+1 means the same series will continue '0' will be made '1' so prev all 0's which were to be made 1 along with this zero is ans+1
                // num will make the previous all encountered '1''s to '0''s for this zero so no +1 with num
                //dp[i]=min(dp[i-1]+1,);
            }
        }
        
        return ans;
    }
};

/*
another method with precompution*/.
  class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int a[n+1];
        a[0]=0;
        for(int i=0;i<n;i++)
        {
            a[i+1]=a[i]+((s[i]=='0')?0:1);
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<=n;i++)
        {
            ans=min(ans,a[i]+(n-i)-(a[n]-a[i]));
        }
        
        return ans;
    }
};
