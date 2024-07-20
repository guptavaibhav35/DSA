#include <bits/stdc++.h>
using namespace std;

//**************************************************************************
//*Height of tree*LC104
//**************************************************************************
// this is the basic question to find out the height of a tree as of the root node
// so for that we will first calculate the height of the left subtree and the right subtree and then add 1 to the max value of them
// this will be our max depth

// this is our only driver code needed, this function has an int return type and takes in just one parameter which is the root of the tree
int maxDepth(TreeNode *root)
{
    // checking if the root of the tree is null or not?
    if (root == NULL)
    {
        // if yes then it means there is no node at the current root of the tree, so the depth is 0,hence we return 0
        return 0;
    }
    // creating the leftDpeth variable to store the leftDepth of the left subtree as of the current node
    int leftDepth = maxDepth(root->left);
    // creating the rightDepth variable to store the rightDepth of the right subtree as of the current node
    int rightDepth = maxDepth(root->right);
    // now creating the depth variable which will store the final depth which will be the max of left depth and right depth and adding 1 to that
    int depth = max(leftDepth, rightDepth) + 1;
    // returning the final depth
    return depth;
}
