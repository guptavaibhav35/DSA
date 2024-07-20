#include <bits/stdc++.h>
using namespace std;

//**************************************************************************
//*Diameter of Tree*LC543
//**************************************************************************
// So the task here is to find the diameter of the binary tree, diameter here means that we need to find the max distance possible in the tree between any 2 nodes
// and this does not have to include the root of the tree, so this distance can be between any 2 nodes but should be the max possible distance in the tree
// now for that we can find the height of the left subtree and the right subtree for every node and then sum them up to get the max distance of the left and the right subtree and then compare it with the left dia and right dia of the node
// so this has to be done for every node and not just the root node
// so we will also have to write the function to calculate the height of the tree for evey node
// then we will be returning the final answer

// this is the function to calculate the height of the tree
// it has an integer return type and takes in only one parameter which is the root of the node
int heightOfTree(TreeNode *root)
{
    // checking if the root of the tree is null or not
    if (root == NULL)
    {
        // if yes then it means that this is not a node and the height of the tree as of this node is 0, so returning 0
        return 0;
    }

    // creating the leftHeight variable to store the height of the left subtree of the current node
    int leftHeight = heightOfTree(root->left);
    // creating the rightHeight variable to store the height of the right subtree of the current node
    int rightHeight = heightOfTree(root->right);
    // creating the height variable to check which is the max height of left and the right subtree and then add 1 for the current node to that answer
    int height = max(leftHeight, rightHeight) + 1;
    // retruning the final height of the tree as of the current node
    return height;
}

// this is the driver function which will help us to calculate the diameter of the binary tree, it has an integer return type and takes in the root of the tree as the only parameter
int diameterOfBinaryTree(TreeNode *root)
{
    // checking if the root of the tree is NULL or not?
    if (root == NULL)
    {
        // if yes then it means that the root of the tree does not have any node and the diameter of the tree as of the current root is 0, hence returning 0 back to the function call
        return 0;
    }
    // creating a leftDia variable to store the diameter of the left subtree of the current node
    int leftDia = diameterOfBinaryTree(root->left);
    // creating a rightDia variable to store the diameter of the right subtree of the current node
    int rightDia = diameterOfBinaryTree(root->right);
    // creating a currentDia variable to find the height of the tree as of the current root, so we are calling this for the left subtree and the right subtree as of the current node
    int currentDia = heightOfTree(root->left) + heightOfTree(root->right);
    // finding the max of the leftDia, rightDia and currentDia and then store it in ans variable
    int ans = max(leftDia, max(currentDia, rightDia));
    // returning the ans variable
    return ans;
}
