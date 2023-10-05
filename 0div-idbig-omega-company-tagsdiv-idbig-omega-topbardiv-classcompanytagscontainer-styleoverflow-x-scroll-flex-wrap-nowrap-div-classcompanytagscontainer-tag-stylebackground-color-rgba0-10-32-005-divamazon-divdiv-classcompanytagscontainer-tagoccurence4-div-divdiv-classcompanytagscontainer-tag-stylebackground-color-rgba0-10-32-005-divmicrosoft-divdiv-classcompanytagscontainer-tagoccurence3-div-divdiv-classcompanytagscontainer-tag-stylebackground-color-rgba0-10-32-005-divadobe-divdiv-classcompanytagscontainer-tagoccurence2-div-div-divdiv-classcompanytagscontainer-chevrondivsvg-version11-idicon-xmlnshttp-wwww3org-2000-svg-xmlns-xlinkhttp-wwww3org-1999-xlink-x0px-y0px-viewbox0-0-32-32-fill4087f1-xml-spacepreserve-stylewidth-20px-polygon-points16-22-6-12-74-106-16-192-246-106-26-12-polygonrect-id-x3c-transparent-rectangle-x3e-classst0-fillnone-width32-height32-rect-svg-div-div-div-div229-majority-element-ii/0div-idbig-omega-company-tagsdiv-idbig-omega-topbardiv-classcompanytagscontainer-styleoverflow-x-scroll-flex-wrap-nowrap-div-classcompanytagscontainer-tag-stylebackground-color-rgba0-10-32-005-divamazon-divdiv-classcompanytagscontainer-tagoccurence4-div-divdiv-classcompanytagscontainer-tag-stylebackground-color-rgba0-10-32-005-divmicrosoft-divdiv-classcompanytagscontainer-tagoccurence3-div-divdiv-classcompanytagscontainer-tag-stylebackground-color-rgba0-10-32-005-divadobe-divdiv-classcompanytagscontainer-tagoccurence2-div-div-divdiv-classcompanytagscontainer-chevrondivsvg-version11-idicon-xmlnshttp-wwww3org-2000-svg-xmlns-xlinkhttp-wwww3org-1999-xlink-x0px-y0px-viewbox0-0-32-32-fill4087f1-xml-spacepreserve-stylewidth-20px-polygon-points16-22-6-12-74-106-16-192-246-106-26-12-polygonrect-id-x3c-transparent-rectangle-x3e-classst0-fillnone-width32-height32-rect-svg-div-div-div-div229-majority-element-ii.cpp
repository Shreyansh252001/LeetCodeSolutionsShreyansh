class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(),count=0,i=0;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        
        for(i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                count++;
            else
            {
                if((count+1)>n/3)
                    ans.push_back(nums[i]);
                
                count=0;
            }
        }
        
        
        count++;
        
        if(count>(n/3))
            ans.push_back(nums[n-1]);
            
        
        return ans;
    }
};