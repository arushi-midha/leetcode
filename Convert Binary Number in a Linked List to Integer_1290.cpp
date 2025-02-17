/*
-------20/1/24-------

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
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
    int getDecimalValue(ListNode* head) {
        vector<int> number;
        ListNode* curr=head;
        while(curr!=NULL){
            number.push_back(curr->val);
            curr=curr->next;
        }
        int ans=0;
        int n=number.size();
        for(int i=0;i<n-1;i++){
            if(number[i]==1){
                ans+=pow(2,n-i-1);
                cout<<"we are adding "<<pow(2,n-i-1);
            }
        }
        if(number[n-1]==1){
            ans++;
        }
        return ans;
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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode* curr=head;
        while(curr!=NULL){
            ans=ans*2+curr->val;
            curr=curr->next;
        }
        
        
    
        return ans;
    }
};