#include <iostream>
#include <queue>  // for level order traversal (❁´◡`❁)🗿
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *InsertDataInBST(Node *root, int d)
{
    int data;
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = InsertDataInBST(root->right, d);
    }
    else if (d == root->data)
    {
        cout << "Same value are not allowed In binary search tree \n";
        cout << "Enter data again :- ";
        cin >> data;
        InsertDataInBST(root, data);
    }
    else
    {
        root->left = InsertDataInBST(root->left, d);
    }
    return root;
}

void EnterData(Node *&root)
{
    int NumberOfNode;
    int data;
    cout << "Enter number of node :- ";
    cin >> NumberOfNode;
    for (int i = 1; i <= NumberOfNode; i++)
    {
        cout << "Insert data :- ";
        cin >> data;
        root = InsertDataInBST(root, data);
    }
}
/* ----------- Level Order traversal ------------- */
void LevelOrderTraverse(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            //   if(temp->left!=NULL)
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
/* -------- Traversal in tree - LNR ---------*/
void InOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << "  ";
    InOrder(root->right);
}
/* Traversal in tree  - NLR*/
void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
/* Traversal in tree  - LRN*/
void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << "  ";
}
/* ---------- Search element in tree ------------ */
void search(Node *root, int value)
{
    // Base case
    if (root == NULL)
    {
        cout << "Value is not present in binary search tree \n";
    }
    if (root->data == value)
    {
        cout << "Yes value is present in binary search tree \n";
    }
    // Base case
    if (root->data > value)
    {
        search(root->right, value);
    }
    else
    {
        search(root->left, value);
    }
}
/* ---------------------- Depth of tree -------------------- */
int DepthOfTree(Node *root)
{
    // Base case;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int depth_L = DepthOfTree(root->left);
        int depth_R = DepthOfTree(root->right);
        if (depth_L > depth_R)
        {
            return depth_L + 1;
        }
        else
        {
            return depth_R + 1;
        }
    }
}
/* Mirror image of tree */
void mirror(Node *node)
{
    if (node == NULL)
        return;
    else
    {
        Node *temp;

        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
/* ------------------ Function to print leaf node ------------------------------ */
void printLeafNodes(Node *root)
{
    // if node is null, return
    if (root==NULL)
        return;

    // if node is leaf node, print its data
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    // if left child exists, check for leaf
    // recursively
    if (root->left != NULL)
    {
        printLeafNodes(root->left);
    }

    // if right child exists, check for leaf
    // recursively
    if (root->right != NULL)
    {
        printLeafNodes(root->right);
    }
}
// to find minimum value in tree
Node *MinValue(Node *root)
{
    
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
/* ---------- Function to delate node in tree ------------ */
Node *DelateNode(Node *root, int value)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == value)
    {
        // 0 child
        if ((root->left == NULL) && (root->right == NULL))
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if ((root->left != NULL) && (root->right == NULL))
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if ((root->left == NULL) && (root->right != NULL))
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = MinValue(root->right)->data;
            root->data = mini;
            root->right = DelateNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > value)
    {
        // left part
        root->left = DelateNode(root->left, value);
        return root;
    }
    else
    {
        root->right = DelateNode(root->right, value);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    // test case :-  10 8 21 7 27 5 4 3 -1
    int choice, choice1;
    int data,data1;
    do
    {
        cout << "1. Create binary search tree \n";
        cout << "2. Insert data in Binary Search Tree \n";
        cout << "3. Display Tree (Traversal) \n";
        cout << "4. Search \n";
        cout << "5. Delete \n";
        cout << "6. Display tree level wise \n";
        cout << "7. Depth of tree \n";
        cout << "8. Mirror image of binary search tree \n";
        cout << "9. Display Leaf node \n";
        cout << "0. Exit \n";
        cout << "Enter your choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            EnterData(root);
            break;
        case 2:
            cout << "Enter data :- ";
            cin >> data;
            InsertDataInBST(root, data);
            break;
        case 3:
            do
            {
                cout << "1. InOrder Traversal \n";
                cout << "2. PreOrder Traversal \n";
                cout << "3. Post order Traversal \n";
                cout << "0. Exit \n";
                cout << "Enter your choice : - ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    cout << "InOrder Traversal :-  ";
                    InOrder(root);
                    cout << "\n";
                    break;
                case 2:
                    cout << "PreOrder Traversal :-  ";
                    PreOrder(root);
                    cout << "\n";
                    break;
                case 3:
                    cout << "PostOrder : - traversal :-  ";
                    PostOrder(root);
                    cout << "\n";
                    break;
                }
            } while (choice1 != 0);
            break;
        case 4:
            search(root, 21);
            break;
        case 5:
            cout << "Enter node to be delate  : -  ";
            cin >> data1;
            DelateNode(root, data1);
            break;
        case 6:
            LevelOrderTraverse(root);
            break;
        case 7:
            cout << "Depth of tree :-  " << DepthOfTree(root) << "\n";
            break;
        case 8:
            mirror(root);
            LevelOrderTraverse(root);
            do
            {
                cout << "1. InOrder Traversal \n";
                cout << "2. PreOrder Traversal \n";
                cout << "3. Post order Traversal \n";
                cout << "0. Exit \n";
                cout << "Enter your choice : - ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    cout << "InOrder Traversal :-  ";
                    InOrder(root);
                    cout << "\n";
                    break;
                case 2:
                    cout << "PreOrder Traversal :-  ";
                    PreOrder(root);
                    cout << "\n";
                    break;
                case 3:
                    cout << "PostOrder : - traversal :-  ";
                    PostOrder(root);
                    cout << "\n";
                    break;
                }
            } while (choice1 != 0);
            break;
        case 9:
            printLeafNodes(root);
            cout << "\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
