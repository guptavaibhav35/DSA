#include <bits/stdc++.h>
using namespace std;

//**************************************************************************
//*Diameter of Tree*LC543
//**************************************************************************
// So the task here is to find the diameter of the binary tree, diameter here means that we need to find the max distance possible in the tree between any 2 nodes
// and this does not have to include the root of the tree, so this distance can be between any 2 nodes but should be the max possible distance in the tree
// so we could have used another method which was to find the height of the tree as of the current nodeand then compare it with the height of the left subtree and the right subtree
// and store the max of these 3, but that is not an efficient way as for every node we are calculating the height of the tree twice, which is not efficient.
// so what we can do is to store the max diameter until now in a variable and just calculate the height of the tree node and then cmpare it with the diameter value.

// Creating a global variable which will help us to store the diamater of the tree and we will keep updating this with the maximum value
int Diameter = 0;
// creating a function solve that will help us solve this problem, it has just one argument which is the root of the tree and return an integer value which is the height of the tree as of the root node
int solve(TreeNode *root)
{
    // checking if the root is null or not?
    if (root == NULL)
    {
        // If yes then it means there is no ndoe and we return a value of 0
        return 0;
    }

    // Recursively calling this function for the left subtree and storing the height of the subtree in left_height variable
    int left_height = solve(root->left);
    // Recursively calling this function for the right subtree and storing the height of the subtree in the right_height variable
    int right_height = solve(root->right);
    // Creating a variable current_diameter which will have the diameter of the tree as of the current node, it will be the sum of the left subtree and the right subtree
    int current_diameter = left_height + right_height;
    // updating value in the global variable with the max of the current_diameter and Diameter
    Diameter = max(Diameter, current_diameter);
    // Returning the max of the left_height,right_height and adding 1 for the current node as the height of the tree.
    return max(left_height, right_height) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    // Creating a temp variable which will have the returned value from solve(root), but this value wont be used
    int temp = solve(root);
    // Returning the Diameter as this has the final and updated diamater of the tree.
    return Diameter;
}
