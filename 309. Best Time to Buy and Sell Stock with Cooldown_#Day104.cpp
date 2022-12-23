class Solution {
public:
    vector<int> ans;
    
    int findans(vector<int> &prices,int i,int n)
    {
        if(i>=n)
            return 0;
        
        if(ans[i]!=-1)
            return ans[i];
        
        int maxval=0;
        
        for(int k=i+1;k<n;k++)
        {
            maxval=max(maxval,prices[k]-prices[i]+findans(prices,k+2,n));
        }
        
        return ans[i]=max(maxval,findans(prices,i+1,n));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        ans.resize(n+1,-1);
        
        return findans(prices,0,n);
    }
};
