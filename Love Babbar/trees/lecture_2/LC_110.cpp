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

// So the main task here is to find if a tree is a balanced binary tree or not ?
// A balanced binary tree is a tree in which the difference of height of a left subtree and right subtree is less than 2.
// And this has to be true for every node and not just the root node
// So what we can do here is to first check the height of the left subtree and the right subtree for every node
// Then we find the absolute difference between the height of left subtree and the right subtree
// If the absolute difference between them is less than 2 then for this node the conditions are satisfied and so as of this node
// The tree is a balanced binary tree
// If the difference of the height of left subtree and the height of right subtree is more than or equal to 2 then it means it is not a
// balanced binary tree.
// Now this condition has to be satisfied for every node of the tree so we make a recursive call to the other nodes in the left and right part
// of the tree and then at last we check if the left part of the subtree is a balanced binary tree and the right subtree is a balanced binary tree
// and also the difference of heights of left subtree and height of right subtree is for the current node is less than 2 then the tree is a balanced binary tree.

// Question link : https://leetcode.com/problems/balanced-binary-tree/description/
class Solution
{
public:
    // This is the function to find out the height of the tree
    // it has only one parameter which is the root node of the tree or the subtree passed, and it has an int return type which will
    // return the height of the tree for the current node
    int heightOfTree(TreeNode *root)
    {
        // this is the base condition where if the root is NULL then the height is 0
        if (root == NULL)
        {
            // returning 0 since the root is NULL so there are no nodes on the left and the right part of the current node
            return 0;
        }

        // doing a recursive call for the left part of the current node
        int leftHeight = heightOfTree(root->left);

        // doing a recursive call for the right part of the current node
        int rightHeight = heightOfTree(root->right);

        // So the main formula to find the height of the tree is to take the max height of left part and the right part and add 1 for the current node
        int ans = max(leftHeight, rightHeight) + 1;

        // returning the final height of the tree as of the current node
        return ans;
    }

    // this is the main driver function which will be called to check if the binary tree is balanced or not?
    // it has a bool return type which will say if the tree is a balanced binary tree or not as of the current or the root node
    // it just has one parameter which is the root of the tree or the subtree in the case of recursive calls
    bool isBalanced(TreeNode *root)
    {
        // This is the base case
        // here we are checking if the root of the tree is null or not
        // if yes then it means the root does not have any nodes on the left and right side of the tree and the height of the
        // tree as of current node is less than 2 so we return true
        if (root == NULL)
        {
            // returning true as the height of the tree as of current node is less than 2
            return true;
        }

        // doing a call to find out the height of the left subtree as of the current node
        int leftHeight = heightOfTree(root->left);

        // doing a call to find out the height of the right subtree as of the current node
        int rightHeight = heightOfTree(root->right);

        // this is the bool variable to check as of the current node, what is the difference of heights of the left and right subtree of the current node
        bool differenceOfHeights;

        // checking if the absolute difference of height of left and right subtree is less than2 or greater than 1 or not
        if (abs(leftHeight - rightHeight) > 1)
        {
            // if true then the difference of heights is not less than 2
            // so marking this variable as false
            differenceOfHeights = false;
        }
        else
        {
            // if false then it means that the difference of heights is less than 2
            //  so marking this variable as true
            differenceOfHeights = true;
        }

        // now doing a recursive call to find if the left subtree is a balanced subtree or not
        bool leftAns = isBalanced(root->left);

        // now doing a recursive call to find if the right subtree is balanced subtree or not
        bool rightAns = isBalanced(root->right);

        // now checking the final condition to see as of the current node is the subtree on the left and right and of current node a balanced subtree or not
        // so we are checking if the differenceOfHeights variable is true, i.e., as of current node the difference of height of left and right subtree is less than 2
        // and checking if the left subtree and the right subtree as of the current node is balanced or not
        if (differenceOfHeights && leftAns && rightAns)
        {
            // if yes then as of current node the tree is a balanced subtree
            return true;
        }
        else
        {
            //  if not then it means that as of the current subtree the tree is not a balanced subtree.
            return false;
        }
    }
};