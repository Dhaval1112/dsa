#include <iostream>
#include <queue>
using namespace std;

// Structure of the node to create tree
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

// To insert nodes into the tree
Node *addNodesInTree()
{
    Node *root;
    cout << "Enter number :: ";
    int num;
    cin >> num;
    root = new Node(num);

    if (num == -1)
    {
        return NULL;
    }
    else
    {
        cout << "Adding at left" << num << endl;
        root->left = addNodesInTree();
        cout << "Adding at right" << num << endl;
        root->right = addNodesInTree();
    }
    return root;
}

// 1. To traverse tree in pre order manner
void printPreOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // PRE (ROOT, LEFT, RIGHT)
    cout << root->data << " ";
    printPreOrderTraversal(root->left);
    printPreOrderTraversal(root->right);
}

// 2. To traverse tree in In order manner
void printInOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // IN (LEFT, ROOT, RIGHT)
    printInOrderTraversal(root->left);
    cout << root->data << " ";
    printInOrderTraversal(root->right);
}

// 3. To traverse tree in post order manner
void printPostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // POST (LEFT, RIGHT, ROOT)
    printPostOrderTraversal(root->left);
    printPostOrderTraversal(root->right);
    cout << root->data << " ";
}

queue<Node *> q;
// 4. Level order traversal
void printLevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (q.empty())
    {
        q.push(root);
        q.push(NULL);
    }

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << node->data << " ";

            // Pushe left and right elements of the current node if those are available
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
}

int main()
{
    cout << "Hellow";
    Node *root = addNodesInTree();
    cout << endl;
    cout << "Pre order traversal :: " << endl;
    printPreOrderTraversal(root);
    cout << endl;
    cout << "In order traversal :: " << endl;
    printInOrderTraversal(root);
    cout << endl;
    cout << "Post order traversal :: " << endl;
    printPostOrderTraversal(root);
    cout << endl;
    cout << "Level order traversal :: " << endl;
    printLevelOrderTraversal(root);

    // 5 8 7 -1 -1 -1 12 6 -1 -1 -1
    return 0;
}