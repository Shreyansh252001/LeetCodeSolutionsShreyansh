static bool cmp(vector<int> &a,vector<int> &b)
  {
    return a[1]>=b[1];
  }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        vector<pair<int,int>> v;
        
       /*() for(int i=0;i<n;i++)
        {
          v.push_back({boxTypes[i][0],boxTypes[i][1]});
        }*/
      
      sort(boxTypes.begin(),boxTypes.end(),cmp);
      
      
      int sum=0,i=0,n=boxTypes.size();
      
    //  for(int i=0;i<n;i++)
       // cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<"\n";
      
      while(i<n && boxTypes[i][0]<=truckSize)
      {
        sum+=(boxTypes[i][1]*boxTypes[i][0]);
        truckSize-=boxTypes[i][0];
        i++;
      }
      
      if(i<n)
          sum+=truckSize*boxTypes[i][1];
      
      return sum;
    }
