#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
TreeNode* newNode(int data)
{
    struct TreeNode* Node = new TreeNode();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}
class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
      /*1. both empty */
    if (p == NULL && q == NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (p != NULL && q != NULL)
    {
        return
        (
            p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
}
 
};
int main(){
    Solution s;
    TreeNode *root1 = newNode(1);
    TreeNode *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    
 
    root2->left = newNode(2);
    root2->right = newNode(3);
 
    if(s.isSameTree(root1, root2))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;


    TreeNode *root3 = newNode(1);
    TreeNode *root4 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(NULL);
    
 
    root4->left = newNode(NULL);
    root4->right = newNode(2);
 
    if(s.isSameTree(root3, root4))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;

    TreeNode *root5 = newNode(1);
    TreeNode *root6 = newNode(1);
    root5->left = newNode(2);
    root5->right = newNode(1);
    
 
    root6->left = newNode(1);
    root6->right = newNode(2);
 
    if(s.isSameTree(root5, root6))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;
 
return 0;
}