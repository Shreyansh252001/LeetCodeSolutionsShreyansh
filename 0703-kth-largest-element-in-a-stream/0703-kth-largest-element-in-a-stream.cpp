// class pq
// {
//     int sz;
//     int curr;
//     vector<int> arr;
    
//     public:
//         pq(int k)
//         {
//             sz=k;
            
//             curr=-1;
            
//             arr.resize(k);
//         }
        
//         void heapify(int idx)
//         {
//            int p=(idx-1)/2;
           
//            while(p>0 && arr[p]>arr[idx])
//            {
//                swap(arr[p],arr[idx]);
               
//                idx=p;
               
//                p=(idx-1)/2;
//            }
           
//         }
    
//         void shiftdown(int i)
//         {
//             int lc=2*i+1;
//             int rc=2*i+2;
//             int maxi=i;

//             if(lc<arr.size() && arr[maxi]>arr[lc])
//             {
//                 maxi=lc;
//             }

//             if(rc<arr.size() && arr[maxi]>arr[rc])
//             {
//                 maxi=rc;
//             }

//             if(maxi!=i)
//             {
//                 swap(arr[maxi],arr[i]);
//                 shiftdown(maxi);
//             }
//         }
    
//         int top()
//         {
//             return arr[0];
//         }
    
//         int pop()
//         {
//             int g=arr[0];
            
//             arr[0]=arr[curr];
            
//             curr--;
            
//             if(curr>=0)
//                 shiftdown(0);
            
//             return g;
//         }
    
//         void push(int a)
//         {
//             arr[++curr]=a;
//             heapify(curr);
//         }
        
//         int size()
//         {
//             return curr+1;
//         }
// };

class KthLargest 
{
    
public:
       int size, maxSize;
    vector<int> array;

    void heapify_down(int parent) {
        int smallest = parent;
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left < size && array[left] < array[smallest])
            smallest = left;

        if (right < size && array[right] < array[smallest])
            smallest = right;

        if (smallest != parent) {
            swap(array[parent], array[smallest]);
            heapify_down(smallest);
        }
    }

    KthLargest(int k, vector<int>& nums) {        
        this->maxSize = k;
        
        this->array = nums;
        this->size = array.size();
        
        // last non leaf node;
        int n = (size / 2) - 1;
        
        for (int i = n; i >= 0; i--) {
            heapify_down(i);
        }
        while (size > k) { // delete until it is equal to k
            swap(array[0], array[size - 1]);
            size--;
            heapify_down(0);
            array.pop_back();
        }
    }
    
    int add(int val) {
        
        size = array.size();
        
        if (size >= maxSize && val < array[0]) return array[0];
        
        else if (size >= maxSize)
            array[0] = val;
        else {
            array.push_back(val);
            size++;
        }
        
        heapify_down(0);
        return array[0];
    }
    
    /*int n;
    pq *obj;
    
     KthLargest(int k, vector<int>& nums) 
     {
         n=k;
         
        obj=new pq(k);
         
           for(int i=0;i<nums.size();i++)
           {
                if(obj->size()>=n)
                {
                    if(obj->top()>nums[i])
                    {
                        obj->pop();
                        obj->push(nums[i]);
                    }
                }
                else
                  obj->push(nums[i]);
           }
        
     }
         
    int add(int val)
    {
        cout<<"done"<<" "<<val<<" ";
        
        if(obj->size()>=n)
        {
            cout<<"overflow"<<" ";
            
            if(obj->top() < val)
            {
              cout<<"exchange possible"<<" ";
                
                 obj->pop();
                 obj->push(val);
            }
        }
        else
          obj->push(val);
        
        cout<<" "<<obj->top()<<"\n";
        
        return obj->top();
    }
    */
//     priority_queue<int,vector<int>,greater<int>> pq;
    
//     KthLargest(int k, vector<int>& nums) {
//         n=k;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(pq.size()>=n)
//         {
//             if(pq.top()<nums[i])
//             { pq.pop();pq.push(nums[i]);}
            
//         }
//         else
//            pq.push(nums[i]);
//         }
//     }
    
//     int add(int val)
//     {
//         if(pq.size()>=n)
//         {
//             if(pq.top()<val)
//             { pq.pop();pq.push(val);}
            
//         }
//         else
//            pq.push(val);
        
//         return pq.top();
//     }
    
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */