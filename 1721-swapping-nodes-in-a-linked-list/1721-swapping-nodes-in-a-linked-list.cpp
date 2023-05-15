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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *first=head,*second=head;
        //ListNode
        
        int n=0;
        
        while(first)
        {
            n++;
            first=first->next;
        }
        
        first=head;
        
        int st=k,ed=n-k+1;
        
        while(st--!=1)
        {
            first=first->next;
        }
        
        while(ed--!=1)
        {
            second=second->next;
        }
        
        int f=first->val;
        first->val=second->val;
        second->val=f;
        
        return head;
    }
};