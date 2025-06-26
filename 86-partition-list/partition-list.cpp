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
    ListNode* partition(ListNode* head, int x) {
        queue<int>q1;
        queue<int>q2;
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp -> val < x){
                q1.push(temp -> val);
            }
            else{
                q2.push(temp -> val);
            }
            temp = temp -> next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp2 = dummy;
        while(!q1.empty()){
            int val = q1.front();
            q1.pop();
            ListNode* nod = new ListNode(val);
            temp2 -> next = nod;
            temp2 = temp2 -> next;
        }
        while(!q2.empty()){
            int val = q2.front();
            q2.pop();
            ListNode* nod1 = new ListNode(val);
            temp2 -> next = nod1;
            temp2 = temp2 -> next;
        }
        return dummy -> next;
    }
};