        map<int,int> c;
        map<int,int>::iterator it;
        vector<int> y;
        for(int i=0;i<nums.size();i++)
        {
            map<int,int>::iterator found=c.find(target-nums[i]);
            if(found!=c.end())
            {
                y.push_back(i);
                y.push_back(found->second);
               // return y;
               // break;
            }
            else
                c.insert(pair<int,int>{nums[i],i});
        }
        //throw new IllegalArgumentException("No two sum solution");
        return y;
