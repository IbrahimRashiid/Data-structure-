#include <iostream>
#include<queue>
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
//check is the tree symmetric
bool isSymetric(TreeNode* root1, TreeNode* root2){
    // both left and right branch don't exist
    if(root1 == NULL && root2 == NULL)
        return true;
    // one branch bigger than the other branch
    if (root1 == NULL || root2 == NULL)
        return false;
    // the left and right branch are both symmetric
    isSymetric(root1->left,root2->right) &&
    isSymetric(root1-> right,root2->left);
}

bool isFoldable(TreeNode* root){
    if(root == NULL)
        return true;
    return isSymetric(root->left,root->right);

}
//deallocate the binary tree
void deleteNodes(TreeNode* root){
    if(root!=NULL){
       deleteNodes(root->left);
       deleteNodes(root->right);
       delete root;
       }
}

int main(){

    // test case 1
    TreeNode *root1 = new TreeNode(85);
    root1->right = new TreeNode(99);
    root1->left = new TreeNode(55);
    root1->left->left = new TreeNode(44);
    root1->left->right = new TreeNode(66);
    root1->right->left = new TreeNode(88);
    root1->right->right = new TreeNode(100);

    cout << "Test Case 1:" << endl << "Expected Answer:True " << endl << "Answer: ";
    if (isFoldable(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    deleteNodes(root1) ;

    // test case 2
    TreeNode* root2 = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(6);
    root2->right->left = new TreeNode(1);
    root2->right->right = new TreeNode(9);
    cout << "Test Case 2:" << endl << "Expected Answer:True " << endl << "Answer: ";
    if (isFoldable(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
       deleteNodes(root2) ;

    // test case 3
    TreeNode* root3 = new TreeNode(20);
    root3->right = new TreeNode(30);
    root3->left = new TreeNode(10);
    root3->left->left = new TreeNode(5);
    root3->left->right = new TreeNode(60);
    cout << "Test Case 3:" << endl << "Expected Answer:False " << endl << "Answer: ";
   if (isFoldable(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
    deleteNodes(root3) ;

    // test case 4
    TreeNode* root4 = new TreeNode(20);
    root4->right = new TreeNode(30);
    root4->left = new TreeNode(10);
    root4->left->left = new TreeNode(0);
    root4->left->right = new TreeNode(15);
    cout << "Test Case 4:" << endl << "Expected Answer:False " << endl << "Answer: ";
    if (isFoldable(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
        deleteNodes(root4) ;

    // test case 5
    TreeNode* root5 = new TreeNode(150);
    root5->left = new TreeNode(15);
    root5->right = new TreeNode(155);

    cout << "Test Case 5:" << endl << "Expected Answer:True " << endl << "Answer: ";
   if (isFoldable(root1))
        cout << "True" << endl << endl;
    else
        cout << "False" << endl << endl;
        deleteNodes(root5) ;
}
