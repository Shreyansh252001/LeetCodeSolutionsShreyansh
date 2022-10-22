
        map<int,Employee*> mp;
        
        for(int i=0;i<emp.size();i++)
        {
            mp[emp[i]->id]=emp[i];
        }
        
        queue<Employee*> q;
        

               q.push(mp[id]);
        
        
        int sum=0;
        Employee* obj;
        
        while(!q.empty())
        {
            
            obj=q.front();
            q.pop();
            sum+=obj->importance;
            
            for(auto it:obj->subordinates)
            {
                q.push(mp[it]);
            }
        }
        
        return sum
