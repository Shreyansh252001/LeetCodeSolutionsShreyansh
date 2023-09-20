class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
        
        if(x>sum)
        {
            return -1;
        }
        
        mp[0]=0;
        
        int longest=0;
        
        sum-=x; //centre array's sum
        
        int val=0;
        
        for(int i=0;i<n;i++)
        {
            val+=nums[i];
            if(mp.find(val-sum)!=mp.end())
            {
                if((val-sum)==0)
                {
                    longest=max(longest,i-mp[val-sum]+1);
                }
                else
                    longest=max(longest,i-mp[val-sum]);
            }
        }
        
        return (longest==0)?((sum==0)?n:-1):(n-longest);
    }
};