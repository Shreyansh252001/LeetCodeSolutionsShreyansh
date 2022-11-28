class RandomizedSet 
{
public:
  
    map<int,int> mp;
    vector<int> ans;
  int length;
  
    RandomizedSet() 
    {
        length=0;
    }
    
    bool insert(int val) 
    {
        if(mp.find(val)!=mp.end())
          return false;
      
      
        mp[val]=length;
          length++;
      
      ans.push_back(val);
      
        return true;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val)==mp.end())
            return false;
      /*
        int idx=mp[val];
        length--;
      
      if(length)
        swap(ans[idx],ans[length-1]);
            
      
      
       ans.pop_back();
      
        if(length)
            mp[ans[idx]]=idx;
      
       mp.erase(val);
      
        return true;
      */
      
        swap(ans[mp[val]], ans[length - 1]);
        ans.pop_back();
        mp[ans[mp[val]]] = mp[val];
        mp.erase(val);
      length--;
        return true;
    }
    
    int getRandom() 
    {
        return ans[rand()%length];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
