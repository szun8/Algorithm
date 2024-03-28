#include <queue>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int answer = 0;
        int curDepth = 0;
        queue<pair<TreeNode*, int>> tree;

        tree.push(pair<TreeNode*, int>(root, 1));

        while (!tree.empty()) {
            pair<TreeNode*, int> curNode = tree.front();
            tree. pop();
            curDepth = curNode.second;

            if (!curNode.first->left && !curNode.first->right) {
                answer = curDepth;
                break;
            } else {
                if (curNode. first->left)
                    tree.push(pair<TreeNode*,int> (curNode.first->left, curDepth+1));
                if (curNode.first->right)
                    tree.push(pair<TreeNode*,int> (curNode.first->right, curDepth+1));
            ｝
            return answer;
        }
    }
};