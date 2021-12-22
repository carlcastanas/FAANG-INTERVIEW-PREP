/*  One way is to store all the nodes, in an array and then return. But we can do something better, instead of traversing entire BST, we can use iterative inorder traversal
    and while going from bottom to up keep on checking if(--k==0) return value.

    TC: O(H+K) O(H) to reach the leftmost/smallest node in the BST & O(K) to find the kth smallest from there doing an inorder search.
    Space: O(H), which in worst case could go upto O(N)
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (!s.empty() || curr)
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;    //going left
            }
            else
            {
                curr = s.top();   //going top
                s.pop();
                if(--k == 0)
                    return curr->val;

                curr=curr->right;    //going right
            }
        } 
        return 0;
    }
};

/* 
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine? 

    Insert/Delete operations takes O(H or logN) time and search takes another O(H+K) so the total complexity would be O(2H+K) without any optimization.
    We can optimize it little a bit to perform more often KthSmallest(), we can achieve the same by maintaining a DLL to store the elements. This way we can perform insert/delete in O(H)
    and search in O(K) just as we do it in Linked List.

    We can use here the same logic as for LRU cache design, and combine an indexing structure (we could keep BST here) with a DLL. Can introduce a new attribute in struct
    of BST node, that stores the address of it's cooresponding DLL node. And that way when we insert a new node in BST, we can access DLL and update there as well.
*/