ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++){
            if (cur == nullptr) {
                return head;
            }
            cur = cur->next;
        }

// 定义 前、中、后三个节点, 前节点就是下一个 k 应该得到的头节点， 中间当作当前的 head,later就是下一个节点。
// 然后用链表翻转, 最终 front 指向的就是翻转后的头节点
        ListNode *middle = head, *front = reverseKGroup(cur, k), *later = head->next;
        for (int i = 0; i < k; i++) {
            middle->next = front;
            front = middle;
            middle = later;
            if (later != nullptr)
                later = later->next;
        }
        return front;

    }