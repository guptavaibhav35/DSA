//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void inorder(Node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// } Driver Code Ends
// User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Question link: https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    // so here the main task is to convert a tree into a sum tree
    // a sum tree is a tree where every node is the sum of all the nodes on the left subtree and the right subtree
    // so we are given a tree with a root node
    // we have to complete the belwo function for that
    // this function has a void return type and has just one argument which is the root of the tree
    // so we will have to make another funtion that will help us convert the existing tree into a sum tree
    // the main idea behind that function will be to reach the leaf nodes first and make their value zero and also storing their values before making them zero so that we can return their value to their parent nodes
    // so we check if the node is a leaf node then we first store the value of the node and then make it zero and then return the previous value of the node back
    // then if the node is not a leaf node then we make a recursive call to the function by also checking if the node has left or right nodes or not
    // if yes then we make the recursive call for the left subtree and the right subtree
    // the recursive calls will be returning the value of the sum of left subtree nodes and right subtree nodes
    // so we first store the current value of the node and then make the current node value as the sum of left subtree sum + right subtree sum
    // then we return the sum of previous value stored for the current node + left subtree sum + right subtree sum

    // this is main function that has to be completed
    // it has a void return type and takes in only parameter which is the root node of the tree
    void toSumTree(Node *node)
    {
        // Your code here
        // calling the dfs function that will help us convert the current tree into a sum tree
        // it has an integer return type and takes in the root of the tree or the subtree
        int s = dfs(node);
        // but the returned value here is of no use
        // so just returning back to the function call
        return;
    }

    // this is the function that will help us convert the current tree into a sumtree
    // it has an int return type and takes in only one argument which is the node of the tree or subtree
    int dfs(Node *node)
    {
        // checking if the node is a leaf node or not?
        if (node->left == NULL && node->right == NULL)
        {
            // if yes then storing the current value of the node
            int temp = node->data;
            // making the value of the current node or the leaf node as 0
            node->data = 0;
            // returning the original stored value of the leaf node
            return temp;
        }

        // creating 2 variables to store the sum of the left subtree and right subtree
        int left_sum = 0;
        int right_sum = 0;

        // checking if the node has a left node or not?
        if (node->left)
        {
            // if yes then making the recursive call to the left subtree of the current node
            // here we will have the sum of the nodes for the left subtree of the current node
            left_sum = dfs(node->left);
        }

        // checking if the node has a right node or not?
        if (node->right)
        {
            // if yes then making the recursive call to the right subtree of the current node
            // here we will have the sum of the nodes for the right subtree of the current node
            right_sum = dfs(node->right);
        }

        // now at this point we have the sum of the left subtree and the right subtree of the current node
        // first we store the value of the current node in a temp variable
        int temp = node->data;
        // then we make the value of the current node = left subtree sum + right subtree sum
        node->data = left_sum + right_sum;

        // then we return the original stored value of the node + left subtree sum + right subtree sum
        return temp + left_sum + right_sum;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends