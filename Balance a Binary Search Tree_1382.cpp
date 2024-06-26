/*
26 june 2024
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
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

    void inorder(vector<int> &values, TreeNode* root){
        if(!root) return;
        inorder(values,root->left);
        values.push_back(root->val);
        inorder(values,root->right);
    }

    TreeNode* createbst(vector<int> values, int start, int end){
        if(start>end) return nullptr;

        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(values[mid]);

        node->left=createbst(values,start,mid-1);
        node->right=createbst(values,mid+1,end);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        TreeNode* curr=root;
        vector<int> values;
        inorder(values,curr);

        return createbst(values,0,values.size()-1);

        


    }
};