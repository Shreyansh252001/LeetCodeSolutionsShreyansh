//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* temp)
    {
        if(temp->next==NULL)
            return temp;
        
        Node* head=reverse(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        
        return head;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        Node* temp=reverse(head);
       
        head=temp;
        
        Node* temp1;
        
        int maxi=temp->data;
        
        while(temp!=NULL)
        {
            temp1=temp->next;
            
            while(temp1!=NULL && temp1->data<maxi)
            {
                
                temp1=temp1->next;
            }
            
            if(temp1)
                maxi=temp1->data;
            
            temp->next=temp1;
            temp=temp->next;
        }
        
        return reverse(head);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends