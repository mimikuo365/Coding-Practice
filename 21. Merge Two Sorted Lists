class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;  
        ListNode *cur1 = l1, *cur2 = l2;
        ListNode head = ListNode(0);
        ListNode *pre = &head;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
              pre->next = cur1;
              pre = cur1;
              cur1 = cur1->next;
            }
            else {
              pre->next = cur2;
              pre = cur2; 
              cur2 = cur2->next;
            }
        }
        if (cur1) pre->next = cur1;
        else if (cur2) pre->next = cur2;
        return head.next;
    }
};
