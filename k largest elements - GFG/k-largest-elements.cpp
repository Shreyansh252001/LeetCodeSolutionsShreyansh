//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class heap
{
    int *arr;
    int n;
    int curr;
    
    public:
           
            
            heap(int k)
            {
                curr=0;
                
                n=k;
                
                arr=new int[k+1];
            }
            
            int left(int i)
            {
                return 2*i+1;
            }
            
            int right(int i)
            {
                return 2*i+2;
            }
            
            int parent(int i)
            {
                return (i-1)/2;
            }

            void heapify(int b);
            
            
            void insert(int b);
            
            
            void arrange(int i)
            {
               /*           int l = left(i);
                int r = right(i);
        
                int smallest = i;
                if (l < heap_size && heap_array[l] < heap_array[i])
                    smallest = l;
                if (r < heap_size && heap_array[r] < heap_array[smallest])
                    smallest = r;
        
                if (smallest != i){
                    swap(heap_array[i], heap_array[smallest]);
                    MinHeapify(smallest);
                }*/
        
                int l=left(i);
                
                int r=right(i);
                
                int mini=i;
                
                if(l<curr && arr[l]>arr[mini])
                {
                    mini=l;
                }
                
                if(r<curr && arr[r]>arr[mini])
                {
                    mini=r;
                }
                
                if(mini!=i)
                {
                    swap(arr[mini],arr[i]);
                    arrange(mini);
                }
            }
            
            int extractmin()
            {
               /* if(curr<=0)
                    return INT_MAX;
            
                if(curr==1)
                {
                    curr--;
                    return arr[0];
                }
                
                int min=arr[0];
                
                arr[0]=arr[curr-1];
                
                --curr;
                
                arrange(0);
                
                return min;*/
                
                if (curr <= 0)
                    return INT_MAX;
                             
                if(curr == 1)
                {
                    curr--;
                    return arr[0];
                }
        
                // remove the minimum value from the heap.
                int root = arr[0];
                
                arr[0] = arr[curr-1];
                
                curr--;
                arrange(0);
        
                return root;
            }
            
};
    void heap::insert(int element)
            {
               
                arr[curr]=element;
                curr++;
                
                heapify(curr-1);
            }
            
            void heap::heapify(int a)
            {
                //int l=return left(a);
                //int r=return right(a);
                
                int p=parent(a);
                
                while(a>0 && arr[p]<arr[a])
                {
                    swap(arr[p],arr[a]);
                    a=p;
                    p=parent(a);
                }
            }
            
            

class Solution
{
public:	
	vector<int> kLargest(int arr[], int n, int k)
	{
	    // code here
        heap *obj=new heap(n);
        
	    vector<int> ans;
	    
	    for(int i=0;i<n;i++)
	    {
	        obj->insert(arr[i]);
	    }
	    
	    for(int i=0;i<k;i++)
	    {
	        ans.push_back(obj->extractmin());
	    }
	    
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends