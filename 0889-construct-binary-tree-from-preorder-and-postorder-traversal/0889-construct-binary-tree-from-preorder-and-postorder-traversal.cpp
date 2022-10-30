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
    void createMapping(vector<int> postorder, map<int,int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[postorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int &preOrderIndex,
                   int postOrderStart, int postOrderEnd, map<int,int> &nodeToIndex, int n){

        if(preOrderIndex >= n || postOrderStart > postOrderEnd){
            return NULL;
        }

        int element = preorder[preOrderIndex++];

        TreeNode* root = new TreeNode(element);
             
        if(postOrderStart == postOrderEnd)
            return root;
        
        int temp = preorder[preOrderIndex];
        int pos = nodeToIndex[temp];

        root->left = solve(preorder, postorder, preOrderIndex, 
                           postOrderStart, pos, nodeToIndex, n);
        root->right = solve(preorder, postorder, preOrderIndex,
                            pos+1, postOrderEnd-1,nodeToIndex,n);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int size = postorder.size();

        map<int,int> nodeToIndex;
        int preOrderIndex = 0;

        createMapping(postorder, nodeToIndex, size);   
        TreeNode* ans = solve(preorder, postorder, preOrderIndex, 0, size-1, nodeToIndex, size);

        return ans;
    }
};