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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode* temp = head;
        vector<int> arr;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin(), arr.end());
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* newTemp = newHead;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* node = new ListNode(arr[i]);
            newTemp->next = node;
            newTemp = node;
        }
        return newHead;
    }
};
