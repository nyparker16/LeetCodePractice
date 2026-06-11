/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head = (list1 -> val < list2 -> val) ? list1 : list2;
        
        ListNode* prev1;
        ListNode* prev2;

        while (list1 != nullptr && list2 != nullptr) {
            while (list1 != nullptr && list1 -> val < list2 -> val) {
                prev1 = list1;
                list1 = list1 -> next;
            }
            if (list1 == nullptr) {
                prev1 -> next = list2;
                break;
            } else if (prev1 != nullptr) {
                prev1 -> next = list2;
            }
            while (list2 != nullptr && list1 -> val >= list2 -> val) {
                prev2 = list2;
                list2 = list2 -> next;
            }
            if (list2 == nullptr) {
                prev2 -> next = list1;
                break;
            } else {
                prev2 -> next = list1;
            }
        }
        return head;
    }
};