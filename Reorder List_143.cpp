/*
25-3-24

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

*/

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
        if(!head) return;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //if(fast->next) slow=slow->next;

        cout<<slow->val<<" "<<fast->val<<" end\n";
        
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(slow!=NULL){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        slow=prev;
        
        while(head && slow){
            fast=head->next;
            prev=slow->next;
            head->next=slow;
            slow->next=fast;
            head=fast;
            slow=prev;
        }
        
        
        
        ListNode* print=head;
        while(print!=NULL){
            cout<<print->val<<" ";
            print=print->next;
        }

        
        
    }
};