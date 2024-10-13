#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildTree(Node *root, int val)
{
    // When it's reaches at the end of the tree by searching element's place to insert it
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }

    // Checking the element's position at left or the right
    if (val < root->val)
    {
        root->left = BuildTree(root->left, val);
    }
    else
    {
        root->right = BuildTree(root->right, val);
    }
    return root;
}

// Creating tree based on the element's inserted by the user
Node *CreateTree(Node *root)
{
    int data = 0;
    // 50 40 60 70 30 45 -1
    do
    {
        cout << "Enter the element of the root :: " << endl;
        cin >> data;
        cin.clear();

        // checking breaking condition of the loop
        if (data == -1)
            break;

        if (root == NULL)
        {
            root = new Node(data);
            cout << "entered value :: root-> val " << root->val;
        }
        else
            BuildTree(root, data);

    } while (true);

    return root;
}

// Checking preorder of the tree
void PreOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->val << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

// Checking postorder of the tree
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // RLN
    PostOrderTraversal(root->right);
    PostOrderTraversal(root->left);
    cout << root->val << " ";
}

// Checking inorder of the tree
void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LNR
    InOrderTraversal(root->left);
    cout << root->val << " ";
    InOrderTraversal(root->right);
}

// Find element from the binary search tree
bool IsElementFound(Node *root, int target)
{
    // When element is null
    if (root == NULL)
    {
        return false;
    }

    // Checking when element found
    if (root->val == target)
    {
        return true;
    }

    // Recursive call to find the element
    return IsElementFound(root->left, target) || IsElementFound(root->right, target);
}

// TO find the maximum element from the root element in the tree
Node *FindMax(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    // Recursive call
    return FindMax(root->right);
}

// Remove element from the tree
Node *DeleteELement(Node *root, int target)
{
    // CHecking base condition when root is null then no element found in the list
    if (root == NULL)
    {
        return NULL;
    }

    // When element found
    if (root->val == target)
    {
        // Checking varies conditions for the details
        // CHecking when left and right both are null
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // When left element is null and right element is available
        else if (root->left == NULL && root->right != NULL)
        {
            Node *newRight = root->right;
            root->right = NULL;
            delete root;
            return newRight;
        }

        // When right element is available and left element is not available
        else if (root->left != NULL && root->right == NULL)
        {
            Node *newLeft = root->left;
            root->left = NULL;
            delete root;
            return newLeft;
        }
        else
        {

            Node *foundElement = FindMax(root);
            root->val = foundElement->val;
            foundElement = NULL;
            delete foundElement;
        }
    }
    else
    {
        // Recursive call when element not matched with the targeted value
        if (target < root->val)
        {
            root->left = DeleteELement(root->left, target);
        }
        else
        {
            root->right = DeleteELement(root->right, target);
        }
    }
    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *element = q.front();
        q.pop();

        if (element == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << element->val << " ";
            if (element->left != NULL)
                q.push(element->left);
            if (element->right != NULL)
                q.push(element->right);
        }
    }
}

int main()
{

    // Construct binary search tree this is the hard thing when to assing root value and make it work need to check every time when i open this code
    Node *root = NULL;
    root = CreateTree(root);

    // Traversal as pre post and in
    // Note: It's same as binary tree nothing changes here
    cout << "PreOrderTraversal :: " << endl;
    PreOrderTraversal(root);
    cout << endl;

    cout << "InOrderTraversall :: " << endl;
    InOrderTraversal(root);
    cout << endl;

    cout << "PostOrderTraversal :: " << endl;
    PostOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal :: " << endl;
    LevelOrderTraversal(root);
    cout << endl;

    // Find element from the binary search tree
    int fnumber;
    cout << endl
         << "Eneter element to find :: ";
    cin >> fnumber;
    cout << "Is " << fnumber << " available in the tree :: " << IsElementFound(root, fnumber);

    return 0;
    // 5 3 6 2 4 7
}
