#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
		right(right) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		// write you code here
		return isIdentical(root, root);
	}
	bool isIdentical(TreeNode* root1, TreeNode* root2) {
		//check if the tree is empty
        if (root1 == NULL && root2 == NULL)
			return true;
        if (root1 !=NULL && root2!=NULL && root1->val == root2->val)
            return isIdentical(root1->right, root2->left) &&
                   isIdentical(root2->right, root1->left);

		return false;
	}

    //deallocate the binary tree
    void deleteNodes(TreeNode* root) {
        if (root != NULL) {
            deleteNodes(root->left);
            deleteNodes(root->right);
            delete root;
        }
    }

};


// add main method and test cases to test your code
int main() {

    // test case 1
    TreeNode *root1 = new TreeNode(85);
    root1->right = new TreeNode(55);
    root1->left = new TreeNode(55);
    root1->left->left = new TreeNode(99);
    root1->left->right = new TreeNode(12);
    root1->right->left = new TreeNode(12);
    root1->right->right = new TreeNode(99);
    Solution testCase1;
    cout << "Test Case 1:" << endl << "Expected Answer:True " << endl << "Answer: ";
    if (testCase1.isSymmetric(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    testCase1.deleteNodes (root1);

    // test case 2
    TreeNode* root2 = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(6);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(2);
    Solution testCase2;
    cout << "Test Case 2:" << endl << "Expected Answer:True " << endl << "Answer: ";
    if (testCase2.isSymmetric(root2))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    testCase2.deleteNodes(root2);

    // test case 3
    TreeNode* root3 = new TreeNode(20);
    root3->right = new TreeNode(10);
    root3->left = new TreeNode(10);
    root3->left->left = new TreeNode(0);
    root3->left->right = new TreeNode(6);
    Solution testCase3;
    cout << "Test Case 3:" << endl << "Expected Answer:False " << endl << "Answer: ";
    if (testCase3.isSymmetric(root3))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    testCase3.deleteNodes(root3);

    // test case 4
    TreeNode* root4 = new TreeNode(20);
    root4->right = new TreeNode(10);
    root4->left = new TreeNode(10);
    root4->left->left = new TreeNode(0);
    root4->left->right = new TreeNode(6);
    Solution testCase4;
    cout << "Test Case 4:" << endl << "Expected Answer:False " << endl << "Answer: ";
    if (testCase4.isSymmetric(root4))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    testCase4.deleteNodes(root4);

    // test case 5
    TreeNode* root5 = new TreeNode(150);
    root5->left = new TreeNode(15);
    root5->right = new TreeNode(15);
    Solution testCase5;
    cout << "Test Case 5:" << endl << "Expected Answer:True " << endl << "Answer: ";
    if (testCase5.isSymmetric(root5))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    testCase5.deleteNodes(root5);

}
