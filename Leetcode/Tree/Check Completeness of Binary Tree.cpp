/*  
    A BT is said to be complete, whose all levels except possibly the last level are completely filled and all the leaf in last level are as left as possible.
    
    One way is to use BFS to do a level order traversal, and whenever we encounter a NULL node then mark it and make sure that we don't encounter any non NULL node after that neither in it's own 
    level nor in it's down level.

    TC: O(N) and Space: O(maximum_width_of_binary_tree) which is equal to O(N) in case of balanced tree O(2^H) H = log2(N)
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        bool seenNull = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(seenNull && curr->left)
                return false;
            else if(curr->left)
                q.push(curr->left);
            
            seenNull = !curr->left?true:false;
            
            if(seenNull && curr->right)
                return false;
            else if(curr->right)
                q.push(curr->right);
            
            seenNull = !curr->right?true:false;
        }
        
        return true;
    }
};

/* Recursive method, by first calculating the total no. of nodes in a Binary Tree and then checking the position of each node */

int countNodes(Node* root) 
{ 
    if (root == NULL) 
        return (0); 
    return (1 + countNodes(root->left) + countNodes(root->right)); 
} 

bool isComplete ( Node* root, int index, int number_nodes) 
{ 
    if (root == NULL) 
        return (true); 
  
    // If index assigned to current node is more than number of nodes in tree, then tree is not complete 
    if (index >= number_nodes) 
        return (false); 

    return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes)); 
} 