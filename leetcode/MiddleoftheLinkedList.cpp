// https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;

        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while(fastNode!=NULL && fastNode->next!=NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        return slowNode;
    }
};
