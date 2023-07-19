class LRUCache {
public:
     list<pair<int,int>> listq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int size;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key)
    {
        auto it=mp.find(key);
        
        if(it==mp.end())
                return -1;
        
        //splice() function here takes the pointer to element stored at the mp[key] and places it at the beginning of the list...
        
        
        //The list::splice() is a built-in function in C++ STL which is used to transfer elements from one list to another. The splice() function can be used in three ways: 
 
/*
        Transfer all the elements of list x into another list at some position.
        Transfer only the element pointed by i from list x into the list at some position.
        Transfers the range [first, last) from list x into another list at some position.
        Syntax: 

list1_name.splice (iterator position, list2)
                or 
list1_name.splice (iterator position, list2, iterator i)
                or 
list1_name.splice (iterator position, list2, iterator first, iterator last)*
        
       // https://www.geeksforgeeks.org/list-splice-function-in-c-stl/
        
        
        
        
        
        
        
        //insert at listq.begin() the pointer to element(value of key ) stored at iterator position given by mp[key]
        
        //in which list to move i.e. list 1 -> (at which position to move in list 1, from which list to move i.e. list2, from which position to move from the list 2)
        
*/
        
        
        listq.splice(listq.begin(),listq,mp[key]);
        
        
        return mp[key]->second;//itertaor ki value as iterator points to {key ,value } pair stored at list in c++
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            //in which list to move i.e. list 1 -> (at which position to move in list 1, from which list to move i.e. list2, from which position to move from the list 2)
            listq.splice(listq.begin(),listq,mp[key]);
            
            mp[key]->second=value;//just change the value in list iterator of pairs no need to change 
            
            return;
        }
        
        if(listq.size()==size)
        {
            int g=listq.back().first;                                                          
            listq.pop_back();
            mp.erase(g);                                  
        }
        
        listq.push_front({key,value});
        
        mp[key]=listq.begin();
    }
};
