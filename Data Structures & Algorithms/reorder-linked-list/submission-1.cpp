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
    void reorderList(ListNode* head) {
        ListNode* copy = head;
        int n = 0;
        // get the count of the list.
        while (copy) {
            n++;
            copy = copy->next;
        }
        // get the first node of the second list.
        int i = 0;
        copy = head;
        while (i < n / 2) {
            i++;
            copy = copy->next;
        }
        // reverse the second half.
        ListNode* prev = nullptr;
        while (copy) {
            ListNode* next = copy->next;
            copy->next = prev;
            prev = copy;
            copy = next;
        }
        // merge both lists.
        ListNode* head2 = prev;
        while (head && head2) {
            ListNode* next = head->next, *next2 = head2->next;
            head->next = head2;
            head2->next = next;
            head = next;
            head2 = next2;
        }
        if (head) {
            head->next = nullptr;
        } else if (head2) {
            head2->next = nullptr;
        }
    }
};
