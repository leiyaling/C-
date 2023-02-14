 ListNode* removeNodes(ListNode* head) {
        if(head->next == nullptr)
            return head;
        ListNode* node = removeNodes(head->next);
        if(node->val > head->val)
            return node;
        head->next = node;
        return head;
    }