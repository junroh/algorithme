//https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int cidx = 1;
        while(cidx<m) {
            prev = cur;
            cur = cur->next;
            cidx++;
        }
        ListNode* next = cur->next;
        while(cidx<n && next!=nullptr) {
            ListNode* tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
            cidx++;
        }
        if(prev!=nullptr) {
            prev->next->next = next;
            prev->next = cur;
        } else {
            head->next = next;
            head = cur;
        }
        return head;
    }
};
