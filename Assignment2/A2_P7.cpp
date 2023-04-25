#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void flipmirror( Node* node)
{
    if (node == nullptr)
    {

        return;
    }
    else
    {
        Node* temp;

        /* do the subtrees */
        flipmirror(node->left);
        flipmirror(node->right);

        /* swap the pointers in this node */
        temp	 = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

Node*root;

Node* insert(Node* root, int item) {
    if (root == NULL) {
//            return new Node(data);
        Node *newnode = new Node(item);
        root = newnode;
    } else if (item <= root->data) {
        root->left = insert(root->left, item);
    } else if (item > root->data) {
        root->right = insert(root->right, item);
    }
    return root;
};
void Insert(int item)
{
    root= insert(root,item);
}


void Inorder(Node*root)
{
    if(root== nullptr)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void flip(Node*n= nullptr)
{
    if (n== nullptr)flipmirror(root);
    else flipmirror(n);
}
void Preorder(Node*root)
{
    if(root== nullptr)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}


void tst1(){





    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    /* Print inorder traversal of the input tree */
    cout << "1)Inorder traversal of the constructed"
         << " tree is" << endl;

    Inorder(root);
    /* Convert tree to its mirror */
    flip(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    Inorder(root);
    cout<<endl;
}
void tst2(){
    Node *root = new Node(9);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(7);

    /* Print inorder traversal of the input tree */
    cout << "2)Inorder traversal of the constructed"
         << " tree is" << endl;

    Inorder(root);
    /* Convert tree to its mirror */
    flip(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    Inorder(root);
    cout<<endl;
}
void tst3(){
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(13);
    root->left->right = new Node(15);

    /* Print inorder traversal of the input tree */
    cout << "3)Inorder traversal of the constructed"
         << " tree is" << endl;

    Inorder(root);
    /* Convert tree to its mirror */
    flip(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    Inorder(root);
    cout<<endl;
}
void tst4(){
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(45);

    /* Print inorder traversal of the input tree */
    cout << "4)Inorder traversal of the constructed"
         << " tree is" << endl;

    Inorder(root);
    /* Convert tree to its mirror */
    flip(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    Inorder(root);
    cout<<endl;
}
void tst5(){
    Node *root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(8);

    /* Print inorder traversal of the input tree */
    cout << "5)Inorder traversal of the constructed"
         << " tree is" << endl;

    Inorder(root);
    /* Convert tree to its mirror */
    flip(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    Inorder(root);
    cout<<endl;
}


int main() {
    cout<<"Test One"<<endl;
    cout<<"*******"<<endl;
    tst1();
    
    cout<<"_____________________________________"<<endl;


    cout<<"Test Two"<<endl;
    cout<<"*******"<<endl;
    tst2();

    cout<<"_____________________________________"<<endl;


    cout<<"Test Three"<<endl;
    cout<<"*******"<<endl;
    tst3();

    cout<<"_____________________________________"<<endl;


    cout<<"Test Four"<<endl;
    cout<<"*******"<<endl;
    tst4();

    cout<<"_____________________________________"<<endl;


    cout<<"Test Five"<<endl;
    cout<<"*******"<<endl;
    tst5();


}
