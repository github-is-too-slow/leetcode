// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 环形链表II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 首先先判断是否有环
        if(!head ||!head -> next) {
            return nullptr;
        }
        ListNode *low = head, *fast = head;
        // 是否相遇过
        bool flag = false;
        while(fast->next && fast->next->next) {
            // 两者相遇
            if(fast == low) {
                if(flag) {
                    break;
                }else {
                    flag = true;
                }
            }
            fast = fast->next->next;
            low = low->next;
        }
        if(!fast->next || !fast->next->next) {
            return nullptr;
        }
        // 此时是因为fast==low相遇了，找出起始位置
        fast = head;
        while(fast != low) {
            fast = fast->next;
            low = low->next;
        }
        return fast;
    }
};