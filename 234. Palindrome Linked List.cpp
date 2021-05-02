// method 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        queue<int> q;
        ListNode *cur = head;
        while (cur) {
            s.push(cur->val);
            q.push(cur->val);
            cur = cur->next;
        }
        while (!s.empty()) {
            if (s.top() != q.front())
                return false;
            // cout << s.top() << " " << q.front() << endl;
            s.pop();
            q.pop();
        }
        return true;
    }
};

// method 2
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* rest_head = reverse(head->next);
        ListNode* rest_tail = head->next;
        rest_tail->next=head;
        head->next = NULL;
        return rest_head;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            if(fast!=NULL)
            slow = slow->next;
        }
        ListNode* rev = reverse(slow->next);
        ListNode* curr = head;
        //cout<<rev->val;
        while(rev!=NULL){
            if(curr->val!=rev->val)
                return false;
            curr=curr->next;
            rev=rev->next;
        }
        return true;
    }
};
