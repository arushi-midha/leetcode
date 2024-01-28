/*
-------28/1/24-------

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int n1=1;
        while(n1<k){
            curr=curr->next;
            n1++;
        }
        int first=curr->val;
        cout<<first<<endl;

        ListNode* tail=reverseValue(head);
        ListNode* curr2=tail;
        int n2=1;
        while(n2<k){
            n2++;
            curr2=curr2->next;
        }


        int end=curr2->val;
        cout<<end;


        curr->val=end;
        curr2->val=first;
        reverseValue(tail);
        return head;
    }


    ListNode* reverseValue(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
};


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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftptr=head;
        ListNode* rightptr=head;
        int n=1;
        while(n<k){
            leftptr=leftptr->next;
            n++;
        }
        ListNode* temp=leftptr;
        while(temp->next!=NULL){
            rightptr=rightptr->next;
            temp=temp->next;
        }
        cout<<leftptr->val<<rightptr->val;
        int x=leftptr->val;
        leftptr->val=rightptr->val;
        rightptr->val=x;

        return head;
    }
};

