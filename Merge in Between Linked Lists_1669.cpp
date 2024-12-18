/*
21/3/24

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
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
    ListNode* mergeInBetween(ListNode* list1, int p, int q, ListNode* list2) {
        int count=0;
        ListNode* curr=list1;
        ListNode* a=NULL;
        ListNode* b=NULL;
        while(curr!=NULL){
            
            if(count==p-1){
                a=curr;
            }
            if(count==q){
                b=curr;
            }
            count++;
            curr=curr->next;
        }

        
        ListNode* curr2=list2;
        if(a!=NULL){
           a->next=curr2; 
        }
        
        while(curr2->next!=NULL){
            curr2=curr2->next;
        }
        curr2->next=b->next;

        
        return list1;
    }
};


/*

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int p, int q, ListNode* list2) {
        int count=0;
        ListNode* curr=list1;
        ListNode* a=list1;
        ListNode* b=list1;
        for(int i=0;i<p-1;i++){
            a=a->next;
        }
        for(int i=0;i<q;i++){
            b=b->next;
        }

        if(a!=NULL){
           a->next=list2; 
        }
        
        while(list2->next!=NULL){
            list2=list2->next;
        }
        list2->next=b->next;

        
        return list1;
    }
};*/