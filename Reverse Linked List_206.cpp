/*
-------20/1/24-------

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

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




/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        stack<int> stk;
        if (curr!=NULL){
            while(curr!=NULL){
                stk.push(curr->val);
                curr=curr->next;
            }
            curr=head;
            while(curr!=NULL){
                curr->val=stk.top();
                stk.pop();
                curr=curr->next;
            }


        }
        
        
       
        return head;
    }
};

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;
        if(curr!=NULL){
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
        }
        return prev;
    }
};