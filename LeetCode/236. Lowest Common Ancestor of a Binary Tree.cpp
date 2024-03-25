#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (root == q || root == p) return root; // 자기 자신이 가장 낮은 조상이 되는 경우
        else if (left != NULL && right != NULL) return root; // 자식 노드들의 공통조상이 자기자신으로 되는 경우
        else if (left != NULL) return left;  // 공통 조상으로 가기 위한 여정 -왼쪽편
        else return right;                  // 공통 조상으로 가기 위한 여정 -오른쪽편
    }
};