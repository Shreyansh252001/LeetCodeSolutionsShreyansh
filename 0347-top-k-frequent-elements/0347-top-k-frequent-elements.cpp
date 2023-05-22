class Solution {
public:
    // class heap{
    //     pair<int,int> p;
    //     int val;
    //     int 
    // }
    /*using priority queue + map*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<int> v;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // will keep in format {frequency,num} [{1,2},{3,5},{6,5},{6,2}] till the size of prirority queue is k
        
        for(auto it:mp)
        {
            if(pq.size()==k)
            {
                
                if(it.second>pq.top().first)// comparing the lowest frequency having number in priority queue if it is less than our upcoming map pair's frequency then we will remove the lowest frequency of priority queue and add the new map pair to the prirority queue in it's place
                {
                  pq.pop();
                    pq.push({it.second,it.first});
                }
                
            }
            else
            {
                pq.push({it.second,it.first});
            }
        }
        
        //popping all the elements of priroity queue
     
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};