#include <bits/stdc++.h>

using namespace std;


class BST {

    struct Node {
        int data;
        Node *left, *right;
    };

    Node *rootPtr = nullptr;

    Node *createNode(int data) {
        Node *new_Node = new Node;
        new_Node->left = NULL;
        new_Node->right = NULL;
        new_Node->data = data;
        return new_Node;
    }

    Node *getTheRightPlace(Node *node, int value) {
        if (node == nullptr)
            return createNode(value);

        if (node->data > value)
            node->left = getTheRightPlace(node->left, value);

        else if (node->data < value)
            node->right = getTheRightPlace(node->right, value);

        return node;
    }

    void PrintInorderTraverse(Node *node) {
        if (node == nullptr)
            return;
        PrintInorderTraverse(node->left);
        cout << node->data << ' ';
        PrintInorderTraverse(node->right);

    }

    int ksmallestElementSumRec(Node *root, int k, int &count) {
        if (root == nullptr)
            return 0;

        int res = ksmallestElementSumRec(root->left, k, count);
        if (count >= k)
            return res;

        res += root->data;

        count++;
        if (count >= k)
            return res;

        return res + ksmallestElementSumRec(root->right, k, count);
    }

public:
    void insert(int value) {
        if (!rootPtr)
            rootPtr = getTheRightPlace(rootPtr, value);
        else {
            getTheRightPlace(rootPtr, value);
        }
    }

    void PrintInorder() {
        PrintInorderTraverse(rootPtr);
    }

    int ksmallestElementSum(int k) {
        int count = 0;
        ksmallestElementSumRec(rootPtr, k, count);
    }

    void deleteNodes(Node *node) {
        Node *d = node;
        if (node != nullptr) {
            Node *dr = node->right;
            Node *dl = node->left;
            delete d;
            deleteNodes(dr);
            deleteNodes(dl);
        } else return;
    }

    ~BST() {
        deleteNodes(rootPtr);
    }
};

void test_1() {
    int a[] = {54, 75, 51, 52, 49, 74, 85};
    BST bst;
    for (auto x: a)
        bst.insert(x);
    int ans = bst.ksmallestElementSum(3);
    if (ans == 152)
        cout << "test passed\n";
    else
        cout << "wrong answer\n";
    cout << "the output is :";
    cout << ans << '\n';
}

void test_2() {
    int a[] = {12, 10, 40, 42, 39, 11, 4};
    BST bst;
    for (auto x: a)
        bst.insert(x);
    int ans = bst.ksmallestElementSum(4);
    if (ans == 37)
        cout << "test passed\n";
    else
        cout << "wrong answer\n";
    cout << "the output is :";
    cout << ans << '\n';
}

void test_3() {
    int a[] = {40, 30, 12, 35, 8, 41};
    BST bst;
    for (auto x: a)
        bst.insert(x);
    int ans = bst.ksmallestElementSum(4);
    if (ans == 85)
        cout << "test passed\n";
    else
        cout << "wrong answer\n";
    cout << "the output is :";
    cout << ans << '\n';
}

void test_4() {
    int a[] = {10, 11, 9};
    BST bst;
    for (auto x: a)
        bst.insert(x);
    int ans = bst.ksmallestElementSum(3);
    if (ans == 30)
        cout << "test passed\n";
    else
        cout << "wrong answer\n";
    cout << "the output is :";
    cout << ans << '\n';
}

void test_5() {
    int a[] = {4, 5, 6, 9};
    BST bst;
    for (auto x: a)
        bst.insert(x);
    int ans = bst.ksmallestElementSum(3);
    if (ans == 15)
        cout << "test passed\n";
    else
        cout << "wrong answer\n";
    cout << "the output is :";
    cout << ans << '\n';
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