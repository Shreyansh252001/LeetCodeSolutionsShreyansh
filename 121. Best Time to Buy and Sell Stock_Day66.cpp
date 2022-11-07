vector<int> v;
  
    int maxProfit(vector<int>& prices) 
    {
      int n=prices.size();
      
      v.resize(n,0);
      
      int gap=0,maxi=INT_MAX,mini=INT_MIN;
      
           
      while(gap<n)
      {
        if(maxi>prices[gap])
        {
          maxi=prices[gap];
        }
        
        mini=max(mini,prices[gap]-maxi);
        
        gap++;
      }
      
      return mini;
    }
