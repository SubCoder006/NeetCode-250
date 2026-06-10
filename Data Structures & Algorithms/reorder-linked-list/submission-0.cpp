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

/*
    1. Find the mid by Floyd's Traversal
    2. Reverse the second half
    3. Merge both taking alternatively
*/

class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // find middle
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // split
        ListNode* second = slow->next;
        slow->next = NULL;

        // reverse
        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;

        // merge
        ListNode* first = head;
        while (second) {
            ListNode* l1 = first->next;
            ListNode* l2 = second->next;

            first->next = second;
            second->next = l1;

            first = l1;
            second = l2;
        }
    }
};
