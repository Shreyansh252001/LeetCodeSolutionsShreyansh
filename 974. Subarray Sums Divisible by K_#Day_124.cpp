 class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int t) {
      
        int count=0,n=nums.size(),sum=0;
        unordered_map<int,int> mp;
        
        mp[0]++;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<=n;j++)
//             {int sum=0;
//                 for(int k=i;k<j;k++)
//                     sum+=nums[k];
                
//                 if(!(sum%t))
//                     count++;
//             }
//         }
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int g=sum%t;
            
           g=(g+t)%t;

            if(mp[g]!=0)
                count+=mp[g];
            
            mp[g]++;
        }
        
        return count;
    }
};
