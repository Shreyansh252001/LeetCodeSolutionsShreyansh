class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n=nums.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
                return{mp[target-nums[i]],i};
            
            mp[nums[i]]=i;
        }
        
        return {-1,-1};
    }
};