class Solution {
public:
    // class heap{
    //     pair<int,int> p;
    //     int val;
    //     int 
    // }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        
        //returntype functionname data structure parameters function content inside
         auto comp=[&mp](int a,int b){return mp[a]>mp[b];};
        
        //as there is no greater specified so this is a normal priority queue
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);
        
        //decltype specifies the return type of comparator function that is the map first part of pair
        
        for(auto it:mp)
        {
            pq.push(it.first);
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<int> top(k);
        
        for(int i=0;i<k;i++)
        {
            top[i]=pq.top();
            pq.pop();
        }
        
        return top;
    }
};