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
   public:
    int getSize(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getSize(head);
        if (sz == n) return head->next;
        ListNode* temp = head;
        int k = sz - n;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
