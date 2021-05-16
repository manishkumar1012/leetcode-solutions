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

/*
    left, root, right
    use stack
    // use a temporary node for movement without altering root, say curr
    while (stack is not empty)
    1. get to the left most node 
    2. pop the top node
    3. print it
    4. get to the right node
    5. go to step 1
    
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (!root)
            return inorder;
        
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        return inorder;
    }
};
