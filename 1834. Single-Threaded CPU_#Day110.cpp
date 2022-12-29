class Solution 
{
public:
    static bool cmp(pair<int,vector<int>> &a,pair<int,vector<int>> &b)
    {
        return a.second[0]==b.second[0]?a.second[1]<b.second[1]:a.second[0]<b.second[0];
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        
        vector<pair<int,vector<int>>> task;
        
        int n=tasks.size();
        
        for(int i=0;i<n;i++)
        {
            task.push_back({i,tasks[i]});
        }
        
        sort(task.begin(),task.end(),cmp);
        
        vector<int> v;
        
        long long cT=0,tI=0;
        
        while(tI<n || !pq.empty())
        {
            if(pq.empty() && cT<task[tI].second[0])
            {
                cT=task[tI].second[0];
            }
            
            while(tI<n && cT>=task[tI].second[0])
            {
                pq.push({task[tI].second[1],task[tI].first});
                ++tI;
            }
            
            auto [processTime,index]=pq.top();
            pq.pop();
            
            cT+=processTime;
            v.push_back(index);
        }
        
        return v;
    }
};
