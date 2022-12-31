/* Construct an Expression Tree from postfix and prefix expression. Perform recursive and non recursive In-order, pre-order and post-order traversal
 */
// Using standard template library(STL) -> stack
#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    char data;
    Node *right;
    Node *left;
    Node(char data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
bool IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
Node *PostfixExpressionTree(string s) // LNR
{
    stack<Node *> st;
    Node *t1, *t2, *t3;
    for (int i = 0; i < s.length(); i++)
    {
        if (!IsOperator(s[i]))
        {
            //    t1=CreateNewNode(s[i]);
            t1 = new Node(s[i]);
            st.push(t1);
        }
        else
        {
            t1 = new Node(s[i]);
            t2 = st.top();
            st.pop();
            t3 = st.top();
            st.pop();
            t1->left = t2;
            t1->right = t3;
            st.push(t1);
        }
    }
    t1 = st.top();
    st.pop();
    return t1;
}
Node *PrefixExpressionTree(string str)
{
    stack<Node *> st;
    int i = str.length() - 1;
    while (i >= 0)
    {
        if (isalpha(str[i]))
        {
            // Create a new node with the operand as the data
            //   node* temp = newNode(str[i]);
            Node *temp = new Node(str[i]);
            // Push the node onto the stack
            st.push(temp);
        }
        else
        {
            // Create a new node with the operator as the data
            Node *temp = new Node(str[i]);
            // Set the left and right children of the node to be the top two elements of the stack
            temp->left = st.top();
            st.pop();
            temp->right = st.top();
            st.pop();
            // Push the new node onto the stack
            st.push(temp);
        }
        i--;
    }
    // The final element in the stack will be the root node of the expression tree
    return st.top();
}
/* Recursively traverse in  expression tree */
void InOrder(Node *root) // LNR
{
    // base case
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data;
    InOrder(root->right);
}
/* Recursively traverse in  expression tree */
void Preorder(Node *root) // NLR
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    Preorder(root->left);
    Preorder(root->right);
}
/* Recursively traverse in  expression tree */
void Postorder(Node *root) // LRN
{
    // base case
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data;
}
/* ---- Non-Recursively traverse in  expression tree ----- */
void NRInOrder(Node *root)
{
    stack<Node *> st;
    Node *temp = root;
    while (temp != NULL || !st.empty())
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->data;
        temp = temp->right;
    }
}
/* ---- Recursively traverse in  expression tree ---- */
void NRPreorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->data;
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
}
/* ---- Recursively traverse in  expression tree ------*/
void NRPostorder(Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data;
        st2.pop();
    }
}

int main()
{
    Node *root;
    string str;
    string str1;
    int choice;
    int choice1;
    do
    {
        cout << "1. Construct an Expression Tree from Postfix expression\n";
        cout << "2. Construct an Expression Tree from Prefix expression\n";
        cout << "0. Exit\n";
        cout << "Enter your choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Postfix expression :-  ";
            cin >> str;
            root = PostfixExpressionTree(str);
            do
            {
                cout << "1. Recursive\n";
                cout << "2. Non Recursive \n";
                cout << "0 .Exit";
                cout << "Enter your choice :-  ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    cout << "Recursively Traversal :-  \n";
                    cout << "In-order Traversal :-  ";
                    InOrder(root);
                    cout << "\n";
                    cout << "Pre-order Traversal :-  ";
                    Preorder(root);
                    cout << "\n";
                    cout << "Post-order Traversal  :-  ";
                    Postorder(root);
                    cout << "\n";
                    break;
                case 2:
                    cout << "Non recursively Traversal \n";
                    cout << "In-order Traversal:-  ";
                    NRInOrder(root);
                    cout << "\n";
                    cout << "Pre-order Traversal :-  ";
                    NRPreorder(root);
                    cout << "\n";
                    cout << "Post-order Traversal :-  ";
                    NRPostorder(root);
                    cout << "\n";
                    break;
                }

            } while (choice1 != 0);

            break;
        case 2:
            cout << "Enter Prefix expression :-  ";
            cin >> str;
            root = PrefixExpressionTree(str);
            do
            {
                cout << "1. Recursive\n";
                cout << "2. Non Recursive \n";
                cout << "0 .Exit";
                cout << "Enter your choice :-  ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    cout << "Recursively Traversal :-  \n";
                    cout << "In-order Traversal :-  ";
                    InOrder(root);
                    cout << "\n";
                    cout << "Pre-order Traversal :-  ";
                    Preorder(root);
                    cout << "\n";
                    cout << "Post-order Traversal  :-  ";
                    Postorder(root);
                    cout << "\n";
                    break;
                case 2:
                    cout << "Non recursively Traversal \n";
                    cout << "In-order Traversal:-  ";
                    NRInOrder(root);
                    cout << "\n";
                    cout << "Pre-order Traversal :-  ";
                    NRPreorder(root);
                    cout << "\n";
                    cout << "Post-order Traversal :-  ";
                    NRPostorder(root);
                    cout << "\n";
                    break;
                }

            } while (choice1 != 0);
            break;
        }

    } while (choice != 0);

    return 0;
}

/* 
Output:-
1. Construct an Expression Tree from Postfix expression
2. Construct an Expression Tree from Prefix expression
0. Exit
Enter your choice :- 1
Enter Postfix expression :-  ab+cd+*
1. Recursive
2. Non Recursive 
0 .ExitEnter your choice :-  1
Recursively Traversal :-  
In-order Traversal :-  d+c*b+a
Pre-order Traversal :-  *+dc+ba
Post-order Traversal  :-  dc+ba+*
1. Recursive
2. Non Recursive 
0 .ExitEnter your choice :-  2
Non recursively Traversal 
In-order Traversal:-  d+c*b+a
Pre-order Traversal :-  *+dc+ba
Post-order Traversal :-  dc+ba+*
1. Recursive
2. Non Recursive
0 .ExitEnter your choice :-  0
1. Construct an Expression Tree from Postfix expression
2. Construct an Expression Tree from Prefix expression
0. Exit
Enter your choice :- 2
Enter Prefix expression :-  *+ab+cd
1. Recursive
2. Non Recursive
0 .ExitEnter your choice :-  1
Recursively Traversal :-
In-order Traversal :-  a+b*c+d
Pre-order Traversal :-  *+ab+cd
Post-order Traversal  :-  ab+cd+*
1. Recursive
2. Non Recursive
0 .ExitEnter your choice :-  2
Non recursively Traversal
In-order Traversal:-  a+b*c+d
Pre-order Traversal :-  *+ab+cd
Post-order Traversal :-  ab+cd+*
1. Recursive
2. Non Recursive
0 .ExitEnter your choice :-  0
1. Construct an Expression Tree from Postfix expression
2. Construct an Expression Tree from Prefix expression
0. Exit
Enter your choice :- 0
 */
