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
    bool isValidBST(TreeNode* root) {
       //Using the DFS method
        
        //Step-1: checking the root node
        if(root == nullptr) {
            return true; // Indicate the end of tree or leaf node
        }
        //Step 2: Prepare the STACK to store the nodes for iteration
        stack<TreeNode*> iterativeStack;
        TreeNode* currentNode = root;
        TreeNode* prevNode = nullptr;
        
        //Step 3: check condition for iteration of complete Tree
        while(currentNode || !iterativeStack.empty()) {
            //Step 4: Push all left nodes to stack at beging
            while(currentNode){
            iterativeStack.push(currentNode);
            currentNode=currentNode->left;
            }
        
            //Step 5: take leaf node and validate the condition
            currentNode = iterativeStack.top();
            iterativeStack.pop();

            //step 6: check with previous node
            // initially previous node is nullptr and even in leaf also not nullptr
            if(prevNode && prevNode->val >= currentNode->val) {
                //Error: Current node should have less value 
                return false;
            }
        
            prevNode = currentNode;
            currentNode=currentNode->right;
        }
        
        return true;
    
    }
};
