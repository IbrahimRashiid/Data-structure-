#include <bits/stdc++.h>

using namespace std;

template<class T>
class BSTFCI {
public:
    struct BSTNode {
        T data;
        BSTNode *left, *right;
    };
private:
    BSTNode *rootPtr;

    BSTNode *createNode(T data) {
        BSTNode *new_Node = new BSTNode;
        new_Node->left = NULL;
        new_Node->right = NULL;
        new_Node->data = data;
        return new_Node;
    }

    BSTNode *getTheRightPlace(BSTNode *node, T value) {
        if (node == nullptr)
            return createNode(value);

        if (node->data > value)
            node->left = getTheRightPlace(node->left, value);

        else if (node->data < value)
            node->right = getTheRightPlace(node->right, value);

        return node;
    }

    void PrintInorderTraverse(BSTNode *node) {
        if (node == nullptr)
            return;
        PrintInorderTraverse(node->left);
        cout << node->data << ' ';
        PrintInorderTraverse(node->right);

    }

    int balanceHeight(BSTNode *currentNode) {
        if (currentNode == nullptr) {
            return 0;
        }

        int leftSubtreeHeight = balanceHeight(currentNode->left);
        if (leftSubtreeHeight == -1) return -1;

        int rightSubtreeHeight = balanceHeight(currentNode->right);
        if (rightSubtreeHeight == -1) return -1;

        if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
            return -1;
        }
        return (max(leftSubtreeHeight, rightSubtreeHeight) + 1);
    }


public:
    BSTFCI() {
        rootPtr = nullptr;
    }

    void insert(T value) {
        if (!rootPtr)
            rootPtr = getTheRightPlace(rootPtr, value);
        else {
            getTheRightPlace(rootPtr, value);
        }
    }

    void PrintInorder() {
        PrintInorderTraverse(rootPtr);
    }

    bool isBalance() {
        return balanceHeight(rootPtr) != -1;
    }

    BSTNode *getroot() const {
        return rootPtr;
    }

    BSTNode *getTheRoot(BSTNode *node, T value) {
        if (node == nullptr)
            return nullptr;

        if (node->data > value) {
            BSTNode *otherNode = getTheRightPlace(node->left, value);
            if (otherNode != nullptr)
                return otherNode;
        } else if (node->data < value) {
            BSTNode *otherNode = getTheRightPlace(node->right, value);
            if (otherNode != nullptr)
                return otherNode;
        } else
            return node;
        return nullptr;
    }

    bool isSimilar(BSTNode *node, BSTNode *root2) {
        if (node == nullptr && root2 == nullptr)
            return true;

        if (node == nullptr || root2 == nullptr)
            return false;


        return (node->data == root2->data &&
                isSimilar(node->left, root2->left) &&
                isSimilar(node->right, root2->right));
    }

    bool isSubTreeNodes(BSTNode *n2) {
        BSTNode *node = getTheRoot(rootPtr, n2->data);
//        if (node != nullptr)
//            cout << node->data << '\n';
        cout << (isSimilar(node, n2) ? "YES" : "NO") << '\n';

    }


    void printInRange(BSTNode *root, int k1, int k2) {
        if (NULL == root)
            return;
        if (k1 < root->data)
            printInRange(root->left, k1, k2);
        if (k1 <= root->data && k2 >= root->data)
            cout << root->data << " ";
        if (k2 > root->data)
            printInRange(root->right, k1, k2);
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

    ~BSTFCI() {
        deleteNodes(rootPtr);
    }
};

template<class T>
bool isSubTree(BSTFCI<T> *t1, BSTFCI<T> *t2) {
    t1->isSubTreeNodes(t2->getroot());
}

void test_1() {

    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {9, 3, 4, 11, 10};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';

    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {9};
    for (auto x: aa)c->insert(x);
    cout << '\n';

    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_2() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 2, 10, 8};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {9, 3, 4, 11, 10};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_3() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 7, 8, 5};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {3, 4};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_4() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {7, 9, 3, 4, 7, 3};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {3, 4};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
}

void test_5() {
    BSTFCI<int> *b;
    b = new BSTFCI<int>;
    int a[] = {5, 6, 9};
    for (auto x: a)b->insert(x);
    cout << '\n';
    cout << "Is it balance ?\n";
    cout << (b->isBalance() ? "YES" : "NO") << '\n';
    cout << "Print in ragne:\n";
    b->printInRange(b->getroot(), 3, 10);

    BSTFCI<int> *c;
    c = new BSTFCI<int>;
    int aa[] = {6};
    for (auto x: aa)c->insert(x);
    cout << '\n';


    cout << "Is C sub tree of B:\n";
    isSubTree(b, c);
    delete b;
    delete c;
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