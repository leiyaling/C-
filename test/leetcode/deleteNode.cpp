ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)
            return head->next;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(head && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return head;
    }