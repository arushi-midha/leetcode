/*
4 july 2024
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

 

Example 1:


Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:


Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 

Constraints:

The number of nodes in the linked list is n.
1 <= n <= 104
0 <= Node.val < n
All the values Node.val are unique.
1 <= nums.length <= n
0 <= nums[i] < n
All the values of nums are unique.
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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* curr=head;
        int components=0;
        bool find=false;
        bool prevfind;
        while(curr!=NULL){
            int x=curr->val;
            prevfind=find;
            find=false;
            for(int i:nums){
                if(i==x){
                    find=true;
                }  
            }
            if(find && !prevfind){
                components++;
            }
            curr=curr->next;
        }
        return components;
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> m1;
        for(int i:nums){
            m1[i]++;
        }

        ListNode* curr=head;
        int components=0;
        bool find=false;
        bool prevfind;
        while(curr!=NULL){
            prevfind=find;
            find=false;
            if(m1[curr->val]==1){
                find=true;
            }
            curr=curr->next;

            if(find && !prevfind){
                components++;
            }
        }
        
        return components;
    }
};