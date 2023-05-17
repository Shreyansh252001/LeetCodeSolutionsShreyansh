/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* temp)
    {
        if(!temp || temp->next==NULL)
            return temp;
        
        ListNode* revst=reverse(temp->next);
        
        temp->next->next=temp;
        
        temp->next=NULL;
        
        return revst;
    }
    
    int pairSum(ListNode* head) 
    {
        int n=0;
        
        ListNode* fwd=head;
        
        while(fwd)
        {
            fwd=fwd->next;
            n++;
        }
        
        fwd=head;
        
        int g=n/2;
        
        while(g--!=1)
        {
            fwd=fwd->next;
        }
     
        ListNode* rev=reverse(fwd);
           
        fwd=head;
        
        int sum=0;
        
        while(rev && fwd)
        {
            cout<<fwd->val<<" "<<rev->val<<"\n";
            
            sum=max(sum,rev->val+fwd->val);
            
            rev=rev->next;
            fwd=fwd->next;
        }
        
        return sum;
    }
};