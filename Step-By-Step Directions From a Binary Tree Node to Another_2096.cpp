/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue
*/

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Map to store parent nodes
        unordered_map<int, TreeNode*> parentMap;

        // Find the start node and populate parent map
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);

        // Perform BFS to find the path
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        // Key: next node, Value: <current node, direction>
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);

        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();

            // If destination is reached, return the path
            if (currentNode->val == destValue) {
                return backtrackPath(currentNode, pathTracker);
            }

            // Check and add parent node
            if (parentMap.find(currentNode->val) != parentMap.end()) {
                TreeNode* parentNode = parentMap[currentNode->val];
                if (visitedNodes.find(parentNode) == visitedNodes.end()) {
                    q.push(parentNode);
                    pathTracker[parentNode] = {currentNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }

            // Check and add left child
            if (currentNode->left != nullptr &&
                visitedNodes.find(currentNode->left) == visitedNodes.end()) {
                q.push(currentNode->left);
                pathTracker[currentNode->left] = {currentNode, "L"};
                visitedNodes.insert(currentNode->left);
            }

            // Check and add right child
            if (currentNode->right != nullptr &&
                visitedNodes.find(currentNode->right) == visitedNodes.end()) {
                q.push(currentNode->right);
                pathTracker[currentNode->right] = {currentNode, "R"};
                visitedNodes.insert(currentNode->right);
            }
        }

        // This line should never be reached if the tree is valid
        return "";
    }

private:
    string backtrackPath(
        TreeNode* node,
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker) {
        string path;
        // Construct the path
        while (pathTracker.count(node)) {
            // Add the directions in reverse order and
            // move on to the previous node
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    void populateParentMap(TreeNode* node,
                           unordered_map<int, TreeNode*>& parentMap) {
        if (node == nullptr) return;

        // Add children to the map and recurse further
        if (node->left != nullptr) {
            parentMap[node->left->val] = node;
            populateParentMap(node->left, parentMap);
        }

        if (node->right != nullptr) {
            parentMap[node->right->val] = node;
            populateParentMap(node->right, parentMap);
        }
    }

    TreeNode* findStartNode(TreeNode* node, int startValue) {
        if (node == nullptr) return nullptr;

        if (node->val == startValue) return node;

        TreeNode* leftResult = findStartNode(node->left, startValue);

        // If left subtree returns a node, it must be StartNode. Return it
        // Otherwise, return whatever is returned by right subtree.
        if (leftResult != nullptr) return leftResult;
        return findStartNode(node->right, startValue);
    }
};