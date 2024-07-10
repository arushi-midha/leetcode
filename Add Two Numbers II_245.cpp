/*
8/7/24
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> list1;
        vector<int> list2;
        while(l1){
            list1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            list2.push_back(l2->val);
            l2=l2->next;
        }
        int n1=list1.size()-1;
        int n2=list2.size()-1;
        int carry=0;
        long sum=0;
        int count=0;
        ListNode* prev=NULL;
        while(n1>=0 or n2>=0 or carry){
            sum=0;
            if(n1>=0){
                sum+=list1[n1];
                n1--;
            }
            if(n2>=0){
                sum+=list2[n2];
                n2--;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            newnode->next=prev;
            prev=newnode;
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

    ListNode* reverselist(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1=reverselist(l1);
        ListNode* r2=reverselist(l2);
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        int sum;
        while(r1 or r2 or carry){
            sum=0;
            if(r1){
                sum+=r1->val;
                r1=r1->next;
            }
            if(r2){
                sum+=r2->val;
                r2=r2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode= new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        ListNode* ans=reverselist(dummy->next);
        return ans;
    }
};