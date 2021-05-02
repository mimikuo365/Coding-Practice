class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        else {
		    unordered_set<ListNode*> nd;
            ListNode *preA, *ptrA = headA, *preB, *ptrB = headB;
            while (ptrA != nullptr) {
              preA = ptrA;
              nd.insert(ptrA);
              ptrA = ptrA->next;
            }
            while (ptrB != nullptr) {
              preB = ptrB;
              if (nd.find(ptrB) != nd.end()) return ptrB;
              ptrB = ptrB->next;            
            }
            return nullptr;
        }
    }
};
