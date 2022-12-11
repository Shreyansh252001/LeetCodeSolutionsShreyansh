 static bool cmp(vector<int> &a,vector<int> &b)
  {
    return b[1]>a[1];
  }
    int eraseOverlapIntervals(vector<vector<int>>& inte) {
        int n=inte.size();
      
      if(n==0)
        return 0;
      
      sort(inte.begin(),inte.end(),cmp);
      
      int end=inte[0][1];
      int count=1;
      
      for(int i=1;i<n;i++)
      {
        if(inte[i][0]>=end)
        {
          end=inte[i][1];
          count++;
        }
      }
      
      return n-count;
      
    
    }
