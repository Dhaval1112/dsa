#include <iostream>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor of the node
    Node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

void AddNodeInTree(Node *newNode, Node *root)
{
    Node *tempNode = root;
    while (tempNode != NULL)
    {
        if (tempNode->val > newNode->val)
        {
            if (tempNode->left != NULL)
            {
                tempNode = tempNode->left;
            }
            else
            {
                tempNode->left = newNode;
            }
        }
        else
        {
            if (tempNode->right != NULL)
            {
                tempNode = tempNode->right;
            }
            else
            {
                tempNode->right = newNode;
            }
        }
    }
}

void contstructTree(Node *root)
{
    int val = 0;
    do
    {
        cout << "Enter element of the node :: " << endl;
        cin >> val;
        Node *newNode = new Node(val);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            AddNodeInTree(newNode, root);
        }
    } while (val != -1);
}

int main()
{

    cout << "Hello world :: ";
    Node *root = NULL;
    contstructTree(root);

    return 0;
}