#include <iostream>
#include <algorithm>
using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode* cur_node, int depth){
        int leftDepth = 0, rightDepth = 0; // 왜 C++인데 쓰레기값이야 ;
        
        if(!cur_node) return depth;
        if(cur_node->left) leftDepth = DFS(cur_node->left, depth+1);
        if(cur_node->right) rightDepth = DFS(cur_node->right, depth+1);

        int cur_dep = max(leftDepth, rightDepth);
        if(depth > cur_dep){
            return depth;
        }
        else return cur_dep;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else return DFS(root, 1);
    }

int main(){
    TreeNode t15 = TreeNode(15);
    TreeNode t7 = TreeNode(7);

    TreeNode t9 = TreeNode(9);
    TreeNode t20 = TreeNode(20, &t15, &t7);

    TreeNode t1 = TreeNode(3, &t9, &t20);

    cout<<maxDepth(&t1);

}