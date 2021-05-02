class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyH = new ListNode (0, head);
        ListNode *cur = head, *pre = dummyH, *beforeL, *left = dummyH;
        bool metEnd = false;
        while (cur != nullptr && !metEnd) {
            beforeL = left;
            left = cur;
            ListNode *tmp = cur;
            for (int i = 0; i < k && !metEnd; i++) {
                if (tmp == nullptr) 
                    metEnd = true;
                else
                    tmp = tmp->next;
            }
            if (!metEnd)
            {
                for (int i = 0; i < k; i++) {
                    ListNode *curNext = cur->next;
                    cur->next = pre;
                    // cout << cur->val << " " << pre->val << endl;
                    pre = cur;
                    cur = curNext;
                }
                beforeL->next = pre;
                left->next = cur;
            }
            // tmp = dummyH->next;
            // while (tmp != nullptr){
            //     cout << tmp->val << " ";
            //     tmp = tmp->next;
            // }
            // cout << endl;
        }
        return dummyH->next;
    }
};
