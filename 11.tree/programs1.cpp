#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// To insert details into the tree
Node *InsertRecords()
{
    Node *root;

    int number;
    cout << "Enter number :: ";
    cin >> number;

    root = new Node(number);

    if (number == -1)
    {
        return NULL;
    }
    else
    {
        // Inserting records logic
        cout << "Inserting at left of " << number << endl;
        root->left = InsertRecords();
        cout << "Inserting at left of " << number << endl;
        root->right = InsertRecords();
    }
    return root;
}

int maximumDepthOfNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = maximumDepthOfNode(root->left);
    int rightDepth = maximumDepthOfNode(root->right);

    int maxDepth = max(leftDepth, rightDepth) + 1;
    return maxDepth;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return leftHeight + rightHeight + 1;
}

//
int getDiameter(Node *root)
{
    if (root = NULL)
        return 0;

    int option1 = getDiameter(root->left);
    int option2 = getDiameter(root->right);
    int option3 = getHeight(root->left) + getHeight(root->right);

    return max(option1, max(option2, option2));
}

int main()
{
    Node *root = InsertRecords();
    cout << "Depth of the current tree is :: " << maximumDepthOfNode(root);
    return 0;
}