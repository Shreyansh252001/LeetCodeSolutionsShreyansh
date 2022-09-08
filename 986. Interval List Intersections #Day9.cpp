
        vector<vector<int>> v;
        
        int it=0,it1=0;
        
        int a,b;
        
        while(it<fl.size() && it1<sl.size())
        {
            if(fl[it][0]<=sl[it1][0])
                a=sl[it1][0];
            else
                a=fl[it][0];
            
            if(fl[it][1]<=sl[it1][1])
                b=fl[it][1];
            else
                b=sl[it1][1];
            
            if(a<=b)
                v.push_back({a,b});
             
            if(fl[it][1]<=sl[it1][1])
                it++;
            else
                it1++;
        }
        
        return v
