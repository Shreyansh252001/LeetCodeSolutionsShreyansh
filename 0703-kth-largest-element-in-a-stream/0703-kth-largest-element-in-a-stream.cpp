class KthLargest {
public:
    int n;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()>=n)
        {
            if(pq.top()<nums[i])
            { pq.pop();pq.push(nums[i]);}
            
        }
        else
           pq.push(nums[i]);
        }
    }
    
    int add(int val)
    {
        if(pq.size()>=n)
        {
            if(pq.top()<val)
            { pq.pop();pq.push(val);}
            
        }
        else
           pq.push(val);
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */