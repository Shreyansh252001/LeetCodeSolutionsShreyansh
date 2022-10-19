unordered_map<Node*,Node*> mp;
    
    Node* dfs(Node* node)
    {
        if(node==NULL)
            return NULL;
        vector<Node*> v;
        
         Node* temp=new Node(node->val);
        
        mp[node]=temp;
        
        for(auto it:node->neighbors)
        {
            if(mp.find(it)!=mp.end())
            {
                v.push_back(mp[it]);
            }
            else
            {
                v.push_back(dfs(it));
            }
        }
        temp->neighbors=v;
        return temp;
    }
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return NULL;
       // Node* head;
       
      //  head=temp;
        if(node->neighbors.size()==0)
        {
             Node* temp=new Node(node->val);
            return temp;
        }

        
        return dfs(node);
    }
