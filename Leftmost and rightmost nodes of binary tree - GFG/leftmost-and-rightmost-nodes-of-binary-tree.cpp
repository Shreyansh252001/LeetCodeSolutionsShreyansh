//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


void printCorner(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        printCorner(root);
        cout<<endl;
    }
    return 0;
}









// } Driver Code Ends


/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

void ans(Node* root)
{
    /*method -1 using size*/
    
    /*
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
        
        for(int i=0;i<n;i++)
        {
            Node* temp=q.front();
            
            if(i==0 || i==n-1)
            {
                cout<<temp->data<<" ";
            }
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
            
            q.pop();
        }
    }*/
    
    queue<Node*> q;
    q.push(NULL);
    q.push(root);
    
    

  
    bool st=false;
    
    Node* temp;
    
    
    while(!q.empty())
    {
        temp=q.front();
             q.pop();
             
       if(temp==NULL)
       {
         if(q.size()==0)
            break;
        
         st=true;
         
         q.push(NULL);
       }
       else
       {
           if(q.front()==NULL ||  st==true)//
           {
             cout<<temp->data<<" ";
             
             st=false;
           }
           
           if(temp->left)
            q.push(temp->left);
          
          
           if(temp->right)
            q.push(temp->right);
       }
      
    }
    //     if(q.front()->data==-1)
    //     {
    //         q.pop();
            
    //          st=true;
             
    //         q.push(f);
    //     }
        
        
    //     if(st)
    //     {
    //         temp=q.front();
             
    //         cout<<temp->data<<" ";
             
    //         q.pop();
    //     }
        
        
    //      if(q.front()->data==-1)
    //     {
    //         cout<<q.front()->data<<" ";
    //     }
        
        
    //     if(temp->left)
    //     {
    //         q.push(temp->left);
    //     }
        
        
    //     if(temp->right)
    //     {
    //         q.push(temp->right);
    //     }
        
        
    //   st=false;
    // }
    
    // if(prev!=pre_prev)
    //     cout<<prev->data<<" ";
}

void printCorner(Node *root)
{
if(!root)
    return;                           
// Your code goes here
    queue<Node*> q;
    
    ans(root);
}