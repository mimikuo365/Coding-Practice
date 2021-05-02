// dummy head
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start = new ListNode(0, head);
        ListNode *cur = head, *pre = start;
        
        for (int i = 1; i < left; i++){
            pre = cur;
            cur = cur->next;            
        }
        ListNode *beforeLeft = pre;
        ListNode *leftLoc = cur;
        for (int i = left; i < right + 1; i++){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        leftLoc->next = cur;
        beforeLeft->next = pre;
        return start->next;
    }
};
