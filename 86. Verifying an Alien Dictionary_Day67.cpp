/*vbery simple and self explanatory if you know structures and specially how to use them to implement TRIES*/    
int mp[26];
    struct Node
    {
        Node* a[26]={NULL};
        char c;
        Node(char c)
        {
            this->c=c;
            isleaf=true;
        }
        bool isleaf;
    };
    
    bool makeNode(Node* root,string w,string order)
    {
        for(int i=0;i<w.length();i++)
        {
            if(root->a[w[i]-'a']==NULL)
            {
                int j=0;
                
                while(order[j]!=w[i])
                    j++;
                
                for(;j<26;j++)
                {
                    if(root->a[order[j]-'a']!=NULL)
                        return false;
                }
                
                root->a[w[i]-'a']=new Node(w[i]);
                root->isleaf=false;
                root=root->a[w[i]-'a'];
            }
            else
                root=root->a[w[i]-'a'];
        }
        
        return root->isleaf==true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) 
    {
        
        
        
        struct Node* root=new Node('/');
        
        for(int i=0;i<words.size();i++)
        {
            if(!makeNode(root,words[i],order))
                return false;
        }
        
        return true;
    }
