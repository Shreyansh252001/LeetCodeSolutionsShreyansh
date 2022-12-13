 void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        node->next=node->next->next;
      node->val=temp->val;
    }
