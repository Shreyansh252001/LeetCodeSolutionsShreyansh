class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
        
        for(auto q:queries)
        {
            int count=0;
            
            for(auto num:nums)
            {
                if(q>=num)
                {
                    q-=num;
                    count++;
                }
                else
                    break;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};
