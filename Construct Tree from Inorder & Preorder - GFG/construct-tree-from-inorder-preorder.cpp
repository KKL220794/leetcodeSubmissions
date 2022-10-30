//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node* solve(int in[], int pre[], int &preOrderIndex, 
                int n, int inOrderStart, int inOrderEnd, map<int,int> &nodeToIndex){
        
        if(preOrderIndex >= n || inOrderStart > inOrderEnd) return NULL;
        
        int element = pre[preOrderIndex++];
        Node* root = new Node(element);
        
        int pos = nodeToIndex[element];
        
        root->left = solve(in, pre, preOrderIndex, n, inOrderStart, pos-1, nodeToIndex);
        root->right = solve(in, pre, preOrderIndex, n, pos+1, inOrderEnd, nodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        
        Node* ans = solve(in, pre, preOrderIndex, n, 0, n-1, nodeToIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends