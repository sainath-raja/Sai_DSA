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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0) return head;
        ListNode* temp = head;
        int len = 1;
        while(temp -> next != nullptr){
            temp = temp -> next;
            len++;
        }
        temp -> next = head;
        if(k % len == 0){
            temp -> next = nullptr;
            return head;
        }
        k = k % len;
        int cnt = len - k;
        ListNode* newtemp = head;
        for(int i = 1; i < cnt; i++){
            newtemp = newtemp -> next;
        }
        ListNode* next = newtemp -> next;
        newtemp -> next = nullptr;
        return next;
    }
};