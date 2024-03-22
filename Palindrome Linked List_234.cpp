/*
22-3-24

Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        bool flag=true;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=curr->next;
        string s1;
        while(curr){
            s1+=curr->val;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        string s2;
        while(prev){
            s2+=prev->val;
            prev=prev->next;
        }
        cout<<s1;
        cout<<"\n"<<s2;
        if(s1==s2){
            return true;
        }
        return false;
    }
};