class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        
        vector<pair<long int,long int>> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]={nums2[i],nums1[i]};
        }
        
        sort(ans.rbegin(),ans.rend());//sort from largest to smallest efficientcy sorting the pair array
        
        priority_queue<long int,vector<long int>,greater<long int>> pq;//short to large the speeds extracted rrom each pair of vectors
        
        long int sums=0,res=0;
        
        for(auto &[e,s]: ans)
        {
            pq.emplace(s);
            
            sums+=s;
            
            if(pq.size()>k)
            {
                sums-=pq.top();
                pq.pop();
            }
            
            if(pq.size()==k)
                res=max(res,sums*e);
        }
        
        return res;
    }
};