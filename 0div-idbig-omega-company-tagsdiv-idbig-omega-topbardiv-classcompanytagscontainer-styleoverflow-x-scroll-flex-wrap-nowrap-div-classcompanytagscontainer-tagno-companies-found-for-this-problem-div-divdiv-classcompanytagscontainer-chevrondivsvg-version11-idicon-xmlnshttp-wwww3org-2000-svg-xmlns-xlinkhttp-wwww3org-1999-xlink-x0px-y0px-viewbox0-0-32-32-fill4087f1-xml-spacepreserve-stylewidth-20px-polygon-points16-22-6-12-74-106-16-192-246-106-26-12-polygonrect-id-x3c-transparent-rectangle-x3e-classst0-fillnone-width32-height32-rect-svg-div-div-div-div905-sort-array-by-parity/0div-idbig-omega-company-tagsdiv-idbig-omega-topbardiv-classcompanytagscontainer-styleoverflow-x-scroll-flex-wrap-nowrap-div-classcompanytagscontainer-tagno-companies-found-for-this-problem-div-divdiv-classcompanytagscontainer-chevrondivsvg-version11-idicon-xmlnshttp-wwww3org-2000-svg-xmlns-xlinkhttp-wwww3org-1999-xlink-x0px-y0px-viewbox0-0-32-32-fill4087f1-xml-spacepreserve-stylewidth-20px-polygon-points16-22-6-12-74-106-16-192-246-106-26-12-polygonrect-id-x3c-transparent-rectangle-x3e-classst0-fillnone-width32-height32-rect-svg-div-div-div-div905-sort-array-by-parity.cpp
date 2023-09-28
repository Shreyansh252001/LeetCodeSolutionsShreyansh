class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n=nums.size(),i=0,j=0;
        int st=0;
        
        while(i<n && j<n)
        {
            st=false;
            
            if(!(nums[i] & 1))
            {
                i++;
            }
            else
                st++;
            
            if(nums[j] & 1)
            {
                j++;
            }
            else
                st++;
            
            if(st==2)
                if(i<j)
                    swap(nums[i],nums[j]);
                else
                {
                    j++;
                }
        }
        
        return nums;
    }
};