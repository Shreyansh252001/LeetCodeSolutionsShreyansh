/*sloww but easy to understans*/
vector<vector<int>> ans;
    
    void comb(int i,int n,int k,vector<int> v)
    {
        if(k==0)
        {
            ans.push_back(v);
            return;
        }
        
        
        
        for(int j=i;j<=n;j++)
        {
            v.push_back(j);
            comb(j+1,n,k-1,v);
           v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> v;
        
            comb(1,n,k,v);
        
        return ans;
    }

/*fast and making two vectors to push inside main vector at a time, may require a dry run for concept clarity*/
/*two versions first has more time than second but less space omplexity then second*/ 
 void comp(int i,int n,int k,vector<int> a)
    {
        if(k==0)
        {
            ans.push_back(a);
            return;
        }
        
        if(n-i+1<k || i>n)
        {
            return;
        }
        
        a.push_back(i);
        
        comp(i+1,n,k-1,a);
        
        a.pop_back();
        
        comp(i+1,n,k,a);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        comp(1,n,k,a);
        return ans;
    }


/*same code with less time*/

 void solve(int n,int k,vector<int>&temp, vector<vector<int>>&ans,int index)
      {
    if(k==0){
        ans.push_back(temp);
        return;
    }
    if(k>n-index+1){
        return;
    }
    if(index>n){
        return;
    }
        temp.push_back(index);
        solve(n,k-1,temp,ans,index+1);
        temp.pop_back();
        solve(n,k,temp,ans,index+1);
}
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> ans;
         vector<int>temp;
         solve(n,k,temp,ans,1);
         return ans;
    }
    
