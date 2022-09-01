 vector<int> a;
    int len;
    vector<int> b;
public:
    
    NumArray(vector<int>& nums) 
    {
        a=nums;
        
        double l=sqrt(nums.size());
        
        len=(int)(ceil(nums.size()/l));
        
        b.resize(len);
        
        for(int i=0;i<nums.size();i++)
        {
            b[i/len]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int i=index/len;
        
        b[i]=b[i]-a[index]+val;
        
        a[index]=val;
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        
        int start=left/len;
        int end=right/len;
        
        if(start==end)
            for(int k=left;k<=right;k++)
                sum+=a[k];
        else
        {
            for(int k=left;k<=(start+1)*len-1;k++)
            {
                sum+=a[k];
            }
            
            for(int k=start+1;k<=end-1;k++)
            {
                sum+=b[k];
            }
            
            for(int k=end*len;k<=right;k++)
            {
                sum+=a[k];
            }
            
        }
        
        return sum;
    }
