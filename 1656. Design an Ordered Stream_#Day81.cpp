 vector<string> s;
    vector<bool> st;
    int i,n;
  
    OrderedStream(int n) {
        this->n=n;
        st.resize(n,false);
        s.resize(n,"");
        i=0;
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey-1]=value;
        
        vector<string> v;
        while(i<n && !st[i] && s[i]!="")
        {
          v.push_back(s[i]);
        st[i]=true;
          i++;
        }
      
      return v;
    }
