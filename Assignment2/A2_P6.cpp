#include <iostream>
#include <cstdlib>
#include <cstdio>     
#include <cstring> 
using namespace std;
 
class TreeNode
{       
    public:
        char value;
        TreeNode *left, *right;
        TreeNode(char data)
        {
            this->value = data;
            this->left = NULL;
            this->right = NULL;
        }
}; 
class Stack
{    
    public:
        TreeNode *treeNode;
        Stack *next;
        Stack(TreeNode *treeNode)
        {
            this->treeNode = treeNode;
            next = NULL;
        }
};
 
class ExpressionTree
{
    private:
        Stack *top;
    public:
        ExpressionTree()
        {
            top = NULL;
        }
        void clear()
        {
            top = NULL;
        }
        void push(TreeNode *ptr)
        {
            if (top == NULL)
                top = new Stack(ptr);
            else
            {
                Stack *ptr1 = new Stack(ptr);
                ptr1->next = top;
                top = ptr1;
            }
        }
 
        TreeNode *pop()
        {
            if (top == NULL)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                TreeNode *ptr = top->treeNode;
                top = top->next;
                return ptr;
            }
        }
 
        TreeNode *peek()
        {
            return top->treeNode;
        }

        bool isDigit(char ch)
        {
            return ch >= '0' && ch <= '9';
        }
 
        bool isOperator(char ch)
        {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }
 
 
        void insert(char val)
        {
            if (isDigit(val))
            {
                TreeNode *nptr = new TreeNode(val);
                push(nptr);
            }
            else if (isOperator(val))
            {
                TreeNode *nptr = new TreeNode(val);
                nptr->left = pop();
                nptr->right = pop();
                push(nptr);
            }
            else
            {
                cout<<"Invalid Expression"<<endl;
                return;
            }
        }
 
      
 
        int toDigit(char ch)
        {
            return ch - '0';
        }
 
        void buildTree(string eqn)
        {
            for (int i = eqn.length() - 1; i >= 0; i--)
                insert(eqn[i]);
        }
 
        double evaluate()
        {
            return evaluate(peek());
        }
 
        double evaluate(TreeNode *ptr)
        {
            if (ptr->left == NULL && ptr->right == NULL)
                return toDigit(ptr->value);
            else
            {
                double result = 0.0;
                double left = evaluate(ptr->left);
                double right = evaluate(ptr->right);
                char op = ptr->value;
                switch (op)
                {
                case '+': 
                    result = left + right; 
                    break;
                case '-': 
                    result = left - right; 
                    break;
                case '*': 
                    result = left * right; 
                    break;
                case '/': 
                    result = left / right; 
                    break;
                default: 
                    result = left + right; 
                    break;
                }
                return result;
            }
        }

        void infix()
        {
            inOrder(peek());
        }
 
        void inOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                inOrder(ptr->left);
                cout<<ptr->value;   
                inOrder(ptr->right);            
            }    
        }   
};
 int main()
{
    string s,x,y,z,o,w;
    s="+-+7*/935/82*/625";
    ExpressionTree a,b,c,d,e,f;
    a.buildTree(s);
    cout<<"Infix   : ";
    a.infix();
    cout<<"\n\nEvaluated Result : "<<a.evaluate()<<endl;

    x="/*+914+53";
    b.buildTree(x);
    cout<<endl<<"Next expression:"<<endl;
    cout<<"Infix   : ";
    b.infix();
    cout<<"\n\nEvaluated Result : "<<b.evaluate()<<endl;

    y="*+51-24";
    c.buildTree(y);
    cout<<endl<<"Next expression:"<<endl;
    cout<<"Infix   : ";
    c.infix();
    cout<<"\n\nEvaluated Result : "<<c.evaluate()<<endl;

    z="-4+23";
    d.buildTree(z);
    cout<<endl<<"Next expression:"<<endl;
    cout<<"Infix   : ";
    d.infix();
    cout<<"\n\nEvaluated Result : "<<d.evaluate()<<endl;

    o="-+231";
    e.buildTree(o);
    cout<<endl<<"Next expression:"<<endl;
    cout<<"Infix   : ";
    e.infix();
    cout<<"\n\nEvaluated Result : "<<e.evaluate()<<endl;

    w="+3*4/82";
    f.buildTree(w);
    cout<<endl<<"Next expression:"<<endl;
    cout<<"Infix   : ";
    f.infix();
    cout<<"\n\nEvaluated Result : "<<f.evaluate()<<endl;



    return 0;
}