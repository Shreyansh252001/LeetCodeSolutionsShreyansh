class Solution 
{
    
public:
    
    //vector<vector<int>> dp;//we cannot do this because declaring such a large 1000000 X 1000000 so using the combination of i and prev in map 
    
    unordered_map<string,int> mp;
    int n,k;
    
   /* int calc(int i,int n,vector<int> &nums,int k)
    {
        if(i>=n)
        {
            return 0;
        }
        
        int g=0;
        
        for(int j=i+1;j<=min(i+k,n-1);j++)
            g=max(g,calc(j,n,nums,k));
        
        return max(g+nums[i],g);
    }
    
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        int u=*max_element(nums.begin(),nums.end());
        
        if(u<0)
        {
            return u;
        }
        int x=INT_MIN;        
        dp.resize(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
            x=max(x,calc(i,n,nums,k));
        
        return x;
    }*/
    
 /*
 Failed TLE
 
    long int calc(int i,int prev,vector<int> &nums)
    {
        if(i==n)
        {
            return 0;
        }
        
        long int sum=0;
        
        string key=to_string(i)+"_"+to_string(prev);
        
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        if(prev==-1)
        {
            sum=max(sum,calc(i+1,prev,nums));
            
            sum=max(sum,nums[i]+calc(i+1,i,nums));
        }
        else if((i-prev)<=k)
        {
            sum=max(sum,nums[i]+calc(i+1,i,nums));
            
            sum=max(sum,calc(i+1,prev,nums));//previously visited i=prev and do not want to take this i which is in range of i-prev  so prev i will remain prev and then move ahead of urrent i
        }
        
        return mp[key]=sum;
    }
    
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        n=nums.size();
        
        this->k=k;
        
        long int g=*max_element(nums.begin(),nums.end());
        
        if(g<0)
            return g;
        
        return calc(0,-1,nums);
    }    
*/
    
/* now iterative approach   */
    
    
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        
       long int n=nums.size(),maxi=nums[0];
        
        long int g=*max_element(nums.begin(),nums.end());
        
        if(g<0)
            return g;
        
        priority_queue<pair<int,int>> pq;
        
        pq.push({nums[0],0});
    
        this->k=k;
        
        /*vector<long int> dp(n);
        
        for(int i=0;i<n;i++)
            dp[i]=nums[i];
        */
        
        for(int i=1;i<n;i++)
        {
            /* due to two for loops it is giving TLE so we can gop for priority queue*/
            /*for(int j=max(i-k,0);j<i;j++)
            {
                dp[i]=max(dp[i],dp[j]+nums[i]);
                
                maxi=max(dp[i],maxi);//it can happen that the subsequence ends at one of the index in between or among the array
            }*/
            
            
             while (i - pq.top().second > k) 
            {
                pq.pop();
            }
            
            /*while((i-pq.top().second)>k)
            {
                pq.pop();
            }*/
            
            
            long int curr = max(0, pq.top().first) + nums[i];
            
            //g=max(0,pq.top().first)+nums[i];
                
            maxi=max(maxi,curr);
            
            pq.push({curr,i});
        }
        
        return maxi;
    }

   /* int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) 
        {
            while (i - heap.top().second > k) 
            {
                heap.pop();
            }

            int curr = max(0, heap.top().first) + nums[i];
            
            ans = max(ans, curr);
            
            heap.push({curr, i});
        }
        
        return ans;
    }*/

};