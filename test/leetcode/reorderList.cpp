//找到链表的中点
//将后半端翻转
//将原链表的两端合并
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return ;

        ListNode* mid = middle(head);
        ListNode* twohead = mid->next;
        mid->next = nullptr;
        twohead = reverseList(twohead);
        mergeList(head,twohead);
    }

    ListNode* middle(ListNode* head)
    {
        ListNode* slow,*fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }
        return prev;
    }

    void mergeList(ListNode* head1,ListNode* head2)
    {
        ListNode* cur1;
        ListNode* cur2;
        while(head1 && head2)
        {
            cur1 = head1->next;
            cur2 = head2->next;

            head1->next = head2;
            head1 = cur1;

            head2->next = head1;
            head2 = cur2;
        }
    }