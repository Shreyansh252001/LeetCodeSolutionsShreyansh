class Solution {
public:

    int bestClosingTime(string c) 
    {
        /*int n=customers.size();

        vector<int> allclosed(n+1,0);
        vector<int> allopen(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                allclosed[i+1]+=1;
            }
            else
            {
                allopen[i+1]+=1;
            }
        }

        for(int i=1;i<=n;i++)
        {
            allclosed[i]+=allclosed[i-1];
            allopen[i]+=allopen[i-1];
        }

        int mini=INT_MAX,index;

        for(int i=1;i<=n;i++)
        {
            //maxi=(maxi;
            
            
            if(mini>(allopen[n]-allopen[i-1]+allclosed[i-1]))
            {   
                mini=allopen[n]-allopen[i-1]+allclosed[i-1];
            index=i-1;}
            
            

        }

        cout<<mini<<" "<<index<<"\n";

          if(allopen[n-1]<mini)
          {   mini=allopen[n-1];index=n;}
         
        cout<<mini<<" "<<index<<"\n";
        
        return index;*/
        
        int n = c.size();
        int prefix[n+1];
        prefix[n] = 0;
        
        for(int i = n-1; i >= 0; i--){
           if(c[i] == 'Y'){
               prefix[i] = 1 + prefix[i+1];
           }
            else prefix[i] = prefix[i+1];
        }
        
        int suffix[n+1];
        suffix[0] = 0;
        
        for(int i = 1; i <= n; i++){
            if(c[i-1] == 'N'){
                suffix[i] = 1 + suffix[i-1];
            }
            else suffix[i] = suffix[i-1];
        }
        

        
        int mini = INT_MAX; 
        int idx = 0;
        for(int i = 0; i <= n; i++){
            int curr = prefix[i] + suffix[i];
            if(mini > curr){
                mini = curr;
                idx = i;
            }
        }
        return idx;
    }


  /*    int bestClosingTime(string customers) {
        int n=customers.length();
        
		// Storing count of 'Y' penalties on right if we close on 'ith index'
        vector<int> right(n+1,0);
        for(int i=n-1;i>=0;i--) right[i] = (i<n-1 ? right[i+1]:0) + (customers[i]=='Y');
        
		 // storing 'N' penalties on left if close on 'ith' index
        vector<int> left(n,0);
        
        int min_penalty=n+1;
        int idx=-1;
        
        for(int i=0;i<n;i++){
            int penalty = right[i] + (i>0 ? left[i-1]:0);
            
            if(min_penalty > penalty){
                min_penalty=min(min_penalty,penalty);
                idx = i;
            }
			
			left[i] = (i>0 ? left[i-1]:0) + (customers[i]=='N');
        }
        
		// if we decide to close after all customers have come
        if(min_penalty > right[n] + left[n-1]) return n;
		
        return idx;
    }*/
};