int n=nums.size();
        
        vector<int> right_max(n);
        
        right_max[n-1]=nums[n-1];
        
        for(int suffix_sum=nums[n-1],i=n-2;i>=0;--i)
        {
            suffix_sum+=nums[i];
            right_max[i]=max(right_max[i+1],suffix_sum);
        }
        
        int max_sum=nums[0];
        int special_sum=nums[0];
        
        for(int i=0,suffix_sum=0,currMax=0;i<n;i++)
        {
            currMax=max(currMax,0)+nums[i];
            
            max_sum=max(max_sum,currMax);
            
            suffix_sum+=nums[i];
            
            if(i+1<n)
            {
                special_sum=max(special_sum,suffix_sum+right_max[i+1]);
            }
        }
        
        return max(max_sum,special_sum);

/*short method*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0],minsum=nums[0],currmax=0,currmin=0,sum=0;
        
        for(int num:nums)
        {
            currmax=max(currmax,0)+num;
            
            maxsum=max(maxsum,currmax);
            
            currmin=min(currmin,0)+num;
            
            minsum=min(minsum,currmin);
            
            sum+=num;
        }
        
        return sum==minsum?maxsum:max(maxsum,sum-minsum);
    }
};
