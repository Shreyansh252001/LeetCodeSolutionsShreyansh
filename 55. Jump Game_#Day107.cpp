class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<=j;)
        {
            j=max(j,j+nums[i]);
            if(j>=n-1)
                return true;
        }
        
        return false;
    }
};
