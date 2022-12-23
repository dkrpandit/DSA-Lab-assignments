/* Q. Implement stack as an abstract data type using singly linked list and use this ADT for conversion of
infix expression to postfix, prefix and evaluation of postfix and prefix expression */
#include <iostream>
#include<math.h>
using namespace std;
/* stack implementation using singly linked list  */
class Node
{
public:
    char data;
    Node *Next;
    Node(char data)
    {
        this->data = data;
        this->Next = NULL;
    }
};
class _stack
{
    Node *top1;

public:
    _stack()
    {
        top1 = NULL;
    }
    void push(char element)
    {
        Node *temp = new Node(element);
        temp->data = element;
        temp->Next = top1;
        top1 = temp;
    }
    void pop()
    {
        Node *temp;
        if (top1 == NULL)
        {
            return;
        }
        else
        {
            temp = top1;
            top1 = top1->Next;
            delete temp;
        }
    }
    char top()
    {
        Node*temp=top1;
        if (top1==NULL)
        {
            // return ;
        }
        else
        {
           return temp->data;
        }
        // return ;
    }
    bool empty()
    {
        if (top1==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
/* ----------- End of stack implementation ----------- */
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infix_to_postfix(string s)
{
    _stack  st;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
string Infix_to_Prefix(string a)
{
    string s = "";
    _stack st;
    for (int i = a.length(); i >= 0; i--)
    {
        s += a[i];
    }

    // return s;
    // for (int i = 0; i < s.length() ; i++)
    // {
    //     if(s[i]==')')
    //     {
    //         s[i]='(';
    //     }
    //     else if(s[i]='(')
    //     {
    //         s[i]=')';
    //     }
    // }
    // return s;

    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i];
        }
        // else if (s[i] == '(')
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        // else if (s[i] == ')')
        else if (s[i] == '(')
        {
            // while (!st.empty() && st.top() != '(')
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    // return s;
    string main_ans = "";
    for (int i = ans.length() - 1; i >= 0; i--)
    {
        main_ans += ans[i];
    }
    return main_ans;
    // return 18;
}


int postfix_evaluation(string s)
{
    _stack st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push((s[i]) - '0');
        }
        // else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        else
        {
            int var2 = st.top();
            st.pop();
            int var1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(var1 + var2);
                break;
            case '-':
                st.push(var1 - var2);
                break;
            case '*':
                st.push(var1 * var2);
                break;
            case '/':
                st.push(var1 / var2);
                break;
            case '^':
                // st.push(Power(var1,var2));
                st.push(pow(var1, var2));
                break;
            }
        }
    }
    return st.top();
}


int prefix_evaluation(string s)
{
    _stack st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int var1 = st.top();
            st.pop();
            int var2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(var1 + var2);
                break;
            case '-':
                st.push(var1 - var2);
                break;
            case '*':
                st.push(var1 * var2);
                break;
            case '/':
                st.push(var1 / var2);
                break;
            case '^':
                // st.push(Power(var1,var2));
                st.push(pow(var1, var2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    // _stack s;
    // s.push('A');
    // s.push('B');
    // s.push('f');
    // s.push('h');
    // s.push('e');
    // s.push('o');
    // // s.pop();
    // cout<<s.top();
    string str;
    int choice;
    do
    {
        cout << "1. Infix to postfix \n";
        cout << "2. Infix to prefix \n";
        cout << "3. Evaluation of Postfix Expression\n";
        cout << "4. Evaluation of Prefix Expression\n";
        cout << "0. Exit \n";
        cout<<"Enter your choice : -  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter input infix expresion :-  ";
            cin >> str;
            cout << infix_to_postfix(str) << "\n";
            break;
        case 2:
            cout << "Enter input infix expresion :-  ";
            cin >> str;
            cout << Infix_to_Prefix(str) << "\n";
            break;
            case 3:
            cout << "Enter postfix  expression (eg. 46+2/5*7+) :-  ";
            cin >> str;
            cout<<postfix_evaluation(str)<<"\n";
            break;
            case 4:
            cout << "Enter prefix  expression (eg. -+7*45+20) :-  ";
            cin >> str;
            cout<<prefix_evaluation(str)<<"\n";
            break;
        }
    } while (choice != 0);
    return 0;
}

/* Output :- 
PS C:\Users\Dharmendra Kumar\DSA with C++> cd "c:\Users\Dharmendra Kumar\DSA with C++\Stacks\" ; if ($?) { g++ stack_lab_3.cpp -o stack_lab_3 } ; if ($?) { .\stack_lab_3 }
1. Infix to postfix 
2. Infix to prefix 
3. Evaluation of Postfix Expression
4. Evaluation of Prefix Expression
0. Exit 
Enter your choice : -  1
Enter input infix expresion :-  (A-B/C)*(A/K-L)
ABC/-AK/L-*
1. Infix to postfix 
2. Infix to prefix 
3. Evaluation of Postfix Expression
4. Evaluation of Prefix Expression
0. Exit 
Enter your choice : -  2
Enter input infix expresion :-  (A-B/C)*(A/K-L)
*-A/BC-/AKL
1. Infix to postfix 
2. Infix to prefix 
3. Evaluation of Postfix Expression
4. Evaluation of Prefix Expression
0. Exit
Enter your choice : -  3
Enter postfix  expression (eg. 46+2/5*7+) :-  46+2/5*7+
32
1. Infix to postfix
2. Infix to prefix
3. Evaluation of Postfix Expression
4. Evaluation of Prefix Expression
0. Exit
Enter your choice : -  4
Enter prefix  expression (eg. -+7*45+20) :-  -+7*45+20
25
1. Infix to postfix
2. Infix to prefix
3. Evaluation of Postfix Expression
4. Evaluation of Prefix Expression
0. Exit
Enter your choice : -  0
PS C:\Users\Dharmendra Kumar\DSA with C++\Stacks>
*/
