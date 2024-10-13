#include <iostream>
#include <algorithm>

using namespace std;

/**
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

// 543. Diameter of Binary Tree
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return findDiameter(root).second;
    }

private:
    pair<int, int> findDiameter(TreeNode *root)
    {
        // Base condition when we get root at left or right
        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> left = findDiameter(root->left);
        pair<int, int> right = findDiameter(root->right);

        int currentHeight = 1 + max(left.first, right.first);

        int currentDiameter =
            max((left.first + right.first), max(left.second, right.second));

        return {currentHeight, currentDiameter};
    }
};

// 110. Balanced Binary Tree

class Solution
{
public:
    bool isBalanced(TreeNode *root) { return balancedTreeHelper(root).first; }

private:
    pair<bool, int> balancedTreeHelper(TreeNode *root)
    {
        // Base condition when we get element as null
        if (root == NULL)
        {
            return {true, 0};
        }

        // Traverse left porsion
        pair<bool, int> left = balancedTreeHelper(root->left);

        // Checking right porsion of the tree
        pair<bool, int> right = balancedTreeHelper(root->right);

        // Finding height including the current node as 1
        int currentHeight = 1 + max(left.second, right.second);
        // CHecking balanced tree condition that
        // 1. left portion of the current tree is balanced.
        // 2. CHecking right portion of the tree is balanced.
        // 3. Checking left and right's absolute values and checking it should be less then equals to the 1 to satisfy the balanced tree condition
        int isBalancedTree =
            left.first && right.first && (abs(left.second - right.second)) <= 1;

        return {isBalancedTree, currentHeight};
    }
};