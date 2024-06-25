/*
25 june 2024
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
 

Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> stk;
        TreeNode* curr=root;
        while(curr!=NULL or !stk.empty()){
            while(curr!=NULL){
                stk.push(curr);
                curr=curr->left;
                
            }
            curr=stk.top();
            stk.pop();
            values.push_back(curr->val);
            curr=curr->right;
        }
        int n=values.size();
        for(int i=n-2;i>-1;i--){
            values[i]=values[i]+values[i+1];
        }
        TreeNode* curr2=root;
        int i=0;
        while(curr2!=NULL or !stk.empty()){
            while(curr2!=NULL){
                stk.push(curr2);
                curr2=curr2->left;
            }
            curr2=stk.top();
            curr2->val=values[i];
            i++;
            stk.pop();
            curr2=curr2->right;
        }
        
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int ans=0;
        stack<TreeNode*> stk;
        TreeNode* curr=root;
        while(curr!=NULL or !stk.empty()){
            while(curr!=NULL){
                stk.push(curr);
                curr=curr->right;
            }
            curr=stk.top();
            stk.pop();
            ans+=curr->val;
            curr->val=ans;
            curr=curr->left;
        }
        
        
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void summing(TreeNode* root, int &ans){
        if(!root) return;
        summing(root->right,ans);
        ans+=root->val;
        root->val=ans;
        summing(root->left,ans);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int ans=0;
        TreeNode* curr=root;
        summing(curr,ans);

        return root;
    }
};