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
    int findPosition(vector<int> inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int                         inorderStart, int inorderEnd, int n){
        
        if(preorderIndex >= n || inorderStart > inorderEnd) return NULL;
        
        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inorder, element, n);
        
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, pos-1, n);
        root->right = solve(preorder, inorder, preorderIndex, pos+1, inorderEnd, n);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preorderIndex = 0;
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, size-1, size);
        
        return ans;
    }
};