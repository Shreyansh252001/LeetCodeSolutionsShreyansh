class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<int> s;
        sort(intervals.begin(),intervals.end(),cmp);
        
        s.push(intervals[0][0]);
        s.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++)
        {
            if(s.top()<intervals[i][0])
            {
                s.push(intervals[i][0]);
                s.push(intervals[i][1]);
            }
            else
            {
                if(s.top()<=intervals[i][1])
                {
                    s.pop();
                    s.push(intervals[i][1]);
                }
            }
        }
        int j=s.size()/2;
        //vector<int> gf;
        vector<vector<int> > e(j,vector<int>(2));
        while(!s.empty())
        {
            //gf.push_back(s.top());
            e[j-1][1]=s.top();
            s.pop();
            e[j-1][0]=s.top();
            //gf.push_back(s.top());
            
            s.pop();
            //e[j-1].push_back(gf);
            //gf.clear();
            j--;
        }
        return e;
    }
};
