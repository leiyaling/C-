ListNode* mergeTwoLists(ListNode* list1,ListNode* list2) {
        if(!list1 && !list2)
            return list1;
        if(!list1)
            return list2;
        if(!list2)
            return list1;  

        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        } 
        if(list1)
            tail->next = list1;
        if(list2)
            tail->next = list2;
        return head->next; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* phead = nullptr;
        for(int i=0; i<lists.size();i++)
        {
            phead = mergeTwoLists(phead,lists[i]);
        }
        return phead;
    }