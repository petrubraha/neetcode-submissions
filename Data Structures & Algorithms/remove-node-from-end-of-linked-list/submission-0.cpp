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
    int getListSize(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = getListSize(head) - n;
        if (index == 0) {
            return head->next;
        }
        ListNode* prev = nullptr, *copy = head;
        for (int i = 0; i < index; ++i) {
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
        return copy;
    }
};
