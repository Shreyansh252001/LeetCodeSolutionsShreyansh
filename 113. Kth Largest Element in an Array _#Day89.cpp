 void heapify(int j,int n,vector<int> &heap)
    {
        int largest=j;
        int left=2*j+1;
        int right=2*j+2;
        
        if(left<n && heap[left]>heap[largest])
            largest=left;
        
        if(right<n && heap[right]>heap[largest])
            largest=right;
        
        if(largest!=j)
        {
            swap(heap[largest],heap[j]);
            
            heapify(largest,n,heap);
        }
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
    
        
        
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(i,n,nums);
        }
        vector<int> b;
        
        while(n>0)
        {
            b.push_back(nums[0]);
            swap(nums[0],nums[n-1]);
            n--;
            heapify(0,n,nums);
        
        }
        
        for(int i=0;i<n;i++)
                cout<<b[i]<<"\n";
        
        return b[k-1];
;    }
