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
        //talking out the total length of linklist
        while(fwd)
        {
            fwd=fwd->next;
            n++;
        }
        
        fwd=head;
        
        int g=n/2;//positioning the head to the start to go till the n/2 so that the linklist turns reverse from half to the end
        
        while(g--!=1)
        {
            fwd=fwd->next;
        }
     //suppose list is 3->2->5->4->1->6 so we send the 5 to till end to be reversed
        ListNode* rev=reverse(fwd);//rev pointer contains the start of the reversed list which is to be used to do addition with head from start
        //rev pointer points to the start of reverse list i.e. end of list to till where both the forward and backward moving pointer collide
        
           fwd=head;
        //now again this fwd acts as a starting point from linklist and rev acts as a starting point from end of linklist
        
        /*list looks like (fwd)3->2->5<-4<-1<-6(rev)
                                     |
                                     V
                                   NULL*/
           
     
        int sum=0;
        
        while(rev && fwd)
        {
           
            
            sum=max(sum,rev->val+fwd->val);
            
            rev=rev->next;
            fwd=fwd->next;
        }
        
        return sum;
    }
};