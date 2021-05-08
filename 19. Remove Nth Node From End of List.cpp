class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *quick = head, *pre = nullptr;
        for (int i = 0; i < n; i++) {
            quick = quick->next;
        }
        while (quick != nullptr) {
            pre = slow;
            slow = slow->next;
            quick = quick->next;
        }
        if (pre) {
            pre->next = slow->next;
            delete slow;
            return head;   
        }
        pre = slow->next;
        delete slow;
        return pre;
    }
};
