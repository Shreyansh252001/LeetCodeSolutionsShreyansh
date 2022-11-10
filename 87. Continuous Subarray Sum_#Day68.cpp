 int n=nums.size(),sum=0;
        if(n<=1)
            return false;
        if(n==2)
            return !((nums[0]+nums[1])%k);
        
        map<int,int> mp;
        
        mp[0]=0;
        
        for(int i=0; i<nums.size(); i++){
            
            sum += nums[i];
            
            if(mp.find(sum % k)==mp.end()){
                mp[sum % k]= i + 1;
            }else{
                if(mp[sum % k] < i){
                    return true;
                }
            }
            
        }
        
        return false;
