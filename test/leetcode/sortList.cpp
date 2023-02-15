ListNode* sortList(ListNode* head) {
        return sortList(head,nullptr);
    }
    //找到链表的中点，以中点为分界，将链表拆分成两个子链表
    ListNode* sortList(ListNode* head,ListNode* tail)
    {   
        //链表的节点个数小于或等于 1，即当链表为空或者链表只包含 1 个节点时，不需要对链表进行拆分和排序
        if(head ==nullptr)
            return head;

        if(head->next == tail)
        {
            head->next =nullptr;
            return head;
        }
        ListNode* slow = head,*fast = head;
        while(fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail)
                fast = fast->next;
        }
        ListNode* mid = slow;
        //对两个子链表分别排序
        return merge(sortList(head,mid),sortList(mid,tail));
    }
    //将两个有序的子链表进行合并
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* phead =new ListNode(0);
        ListNode* tail = phead;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
             tail = tail->next;
        }
        if(head1)
            tail->next = head1;
        if(head2)
            tail->next = head2;
        return phead->next;
    }