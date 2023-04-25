#include <bits/stdc++.h>

using namespace std;

class BST {
    struct BSTNode {
        char data;
        BSTNode *left, *right;
    };

    BSTNode *rootPtr = nullptr;

    string in;

    BSTNode *createNode(char data) {
        BSTNode *new_Node = new BSTNode;
        new_Node->left = NULL;
        new_Node->right = NULL;
        new_Node->data = data;
        return new_Node;
    }

    bool isRight(char nodeChar, char inserted) {
        return (in.find(nodeChar) < in.find(inserted));
    }

    BSTNode *getTheRightPlace(BSTNode *node, char value) {
        if (node == nullptr)
            return createNode(value);

        if (!isRight(node->data, value))
            node->left = getTheRightPlace(node->left, value);

        else
            node->right = getTheRightPlace(node->right, value);

        return node;
    }

    void PrintPostTraverse(BSTNode *node) {
        if (node == nullptr)
            return;
        PrintPostTraverse(node->left);
        PrintPostTraverse(node->right);
        cout << node->data << ' ';

    }


public:
    void setin(string in) {
        this->in = in ;
    }

    void insert(char value) {
        if (!rootPtr)
            rootPtr = getTheRightPlace(rootPtr, value);
        else {
            getTheRightPlace(rootPtr, value);
        }
    }

    void printPost() {
        PrintPostTraverse(rootPtr);
        cout<<'\n';
    }
    void deleteNodes(BSTNode *node) {
        BSTNode *d = node;
        if (node != nullptr) {
            BSTNode *dr = node->right;
            BSTNode *dl = node->left;
            delete d;
            deleteNodes(dr);
            deleteNodes(dl);
        } else return;
    }

    ~BST() {
        deleteNodes(rootPtr);
    }

};

void printPostOrder(string preorder, string inorder) {
    string pre = preorder;
    string in = inorder;
    BST b;
    b.setin(in);
    for (auto x: pre)
        b.insert(x);
    b.printPost();
}

void test_1() {
    printPostOrder("ABFGC", "FBGAC");
}

void test_2() {
    printPostOrder("WQETY", "EQYTW");
}

void test_3() {
    printPostOrder("UIODJ", "JDUOI");
}

void test_4() {
    printPostOrder("HGKCL", "KCLGH");
}

void test_5() {
    printPostOrder("NLUIS", "LNSIU");
}

int main() {
    cout << "--------test one -------\n";
    test_1();
    cout << "--------test two -------\n";
    test_2();
    cout << "--------test three -------\n";
    test_3();
    cout << "--------test four -------\n";
    test_4();
    cout << "--------test five -------\n";
    test_5();

    return 0;
}