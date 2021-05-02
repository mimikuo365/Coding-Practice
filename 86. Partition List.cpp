class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *head_min = nullptr, *tail_min = nullptr, *head_max = nullptr, *tail_max = nullptr;
        ListNode *cur = head;
        ListNode *curNext;
        while (cur != nullptr)
        {
            curNext = cur->next;
            if (cur->val < x)
            {
                if (head_min == nullptr)
                {
                    head_min = cur;
                    tail_min = cur; 
                    cout << "Head_min: " << tail_min->val << endl;
                }
                else
                {
                    cout << tail_min->val << ' ';
                    tail_min->next = cur;
                    tail_min = cur;
                    cout << tail_min->val << endl;
                }
            }
            else
            {
                if (head_max == nullptr)
                {
                    head_max = cur;
                    tail_max = cur; 
                    cout << "Head_max: " << tail_max->val << endl;
                }
                else
                {
                    cout << tail_max->val << ' ';
                    tail_max->next = cur;
                    tail_max = cur;
                    cout << tail_max->val << endl;
                }
            }
            cur = curNext;
        }
        
        if (head_min == nullptr && head_max == nullptr)
            return nullptr;
        else if (head_min == nullptr && head_max != nullptr)
        {
            tail_max->next = nullptr;
            return head_max;
        }
        else if (head_min != nullptr && head_max == nullptr)
        {
            tail_min->next = nullptr;
            return head_min;
        }
        else
        {
            tail_min->next = head_max;
            tail_max->next = nullptr;
            return head_min;
        }
    }
};
